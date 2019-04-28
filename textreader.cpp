#include "textreader.h"

TextReader::TextReader()
{
    QList<QVector<int>> coordinateList;
    QList<QVector<int>> indicesList;
    QFile file1("C:\\Users\\Victor\\Documents\\coordinates.txt");

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
        List list1 = List(coordinateList);

        // set pointer values in nodes
        for(int i = 0; i < 75; i++){
            int firstIndice = indicesList[i][0];
            int secondIndice = indicesList[i][1];
            if(secondIndice!= 0){
                list1.setPointer(list1.returnAddress(firstIndice), list1.returnAddress(secondIndice), i);
            }
            else{
                list1.setPointer(list1.returnAddress(firstIndice), nullptr, i);
            }
        }

        /*      GET LIST OF COORDINATES
       QList<QVector<int>> nodeList;
       int numOfTurns = 6;
       int pos = 1;
       int counter = 1;

       //Vertically -> false
       //Horizontally -> true

       while(counter <= numOfTurns){
           nodeList.append(list1.getNextNode(pos, counter, true).getCoordinates(list1.getNextNode(pos, counter, true)));
           counter++;
       }

       for(int i = 0; i < nodeList.size(); i++){
           qDebug() << nodeList.at(i);
       }*/
}
