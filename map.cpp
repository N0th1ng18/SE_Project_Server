#include "map.h"

//C:\\Users\\Victor\\Documents\\coordinates.txt
Map::Map(QString fileLocation)
{

    QFile file1(fileLocation);

    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

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
            else {
                indicesList.append(coordinates);
            }
     }
        // initialize nodes
        list = List(coordinateList);

        // set pointer values in nodes
        for(int i = 0; i < 75; i++){
            int firstIndice = indicesList[i][0];
            int secondIndice = indicesList[i][1];
            if(secondIndice!= 0){
                list.setPointer(list.returnAddress(firstIndice), list.returnAddress(secondIndice), i);
            }
            else{
                list.setPointer(list.returnAddress(firstIndice), nullptr, i);
            }
        }

}

Map::~Map()
{

}

/*
___ Map::movePlayer(space, roll, playerID)
{
    //Starting at space n

    //create least for player movements

    for(roll)
        //go to next pos
        list.
        //calculate random position based on playerID
        //add this position to list

    return list

}
*/
