#include "map.h"

Map::Map(QString fileLocation)
{
    head = nullptr;

    loadMap(fileLocation);
}
Map::~Map()
{

}

Node* Map::getHead(){
    return head;
}

//Can Only Do this once due to lack of delete Functionality
bool Map::loadMap(QString fileLocation)
{
    QFile file1(fileLocation);

    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed To Open Map File";
        return false;
    }

    // Read values from file
    QTextStream in(&file1);
    while (!in.atEnd()) {
        QVector<int> coordinates;
        QString line = in.readLine();
        QStringList trimmedLine = line.split("\t");

        for (QString str : trimmedLine){
            coordinates.append(str.toInt());
        }
        if(coordinates.size()== 4){
            coordinateList.append(coordinates);
        }
     }
    // initialize nodes
    this->head = new Node(coordinateList[0].at(0), coordinateList[0].at(1) ,coordinateList[0].at(2) ,coordinateList[0].at(3));
    Node* current = this->head;
    Node* prev = this->head;

    // set pointer values in nodes
    for(int i = 0; i < coordinateList.size() - 1; i++){
        //create next node
        current = new Node(coordinateList[i+1].at(0), coordinateList[i+1].at(1) ,coordinateList[i+1].at(2) ,coordinateList[i+1].at(3));
        prev->setPtr1(current);
        prev = current;
    }

    return true;
}

int Map::movePlayer(Node* startingNode, int roll, std::vector<Point*>& outList){
    //Check for node problem. This should never happen until the last node in the map.
    if(startingNode == nullptr)
    {
        return 0;//Error in initial parameters.
    }

    Node* current = startingNode;

    for(int i = 0; i < roll; i++){

        if(current->getPtr1() == nullptr)
        {
            return 2; //Player has reached the end of the map.
        }

        current = current->getPtr1();
        outList.push_back(new Point(calcRandPos(current->getX1(), current->getX2()),calcRandPos(current->getY1(), current->getY2())));
    }
    startingNode = current;

    return 1; //It worked.
}

//Map Coordinates are locked to x1 > x2 and y1 > y2
int Map::calcRandPos(int x1, int x2)
{
    int dif = x2 - x1;
    int randomNum = QRandomGenerator::global()->generate() % (dif + 1);
    return x1 + randomNum;
}
