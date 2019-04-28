#include "list.h"

List::List()
{

}

List::List(QList<QVector<int>> coordinateList){
    for(int i = 0; i < coordinateList.size(); i++){
        QVector<int> qv = coordinateList[i];
        addNode(Node(qv));
    }
}

void List::addNode(Node a){
    boardList.append(a);
}

Node * List::returnAddress(int i){
    return &boardList[i];
}

void List::setPointer(Node * n, Node * m, int i){
    boardList[i].setPointer(n, m);
}

Node List::getNode(int pos){
    return boardList[pos];
}

Node List::getNextNode(int pos, int counter, vector<QVector2D>* listOfMoves){
    if(counter == 1){
        if (QRandomGenerator::global()->generate() % 2){
            //calculate point to list of moves
            //boardList[pos].getCoordinates();
            return boardList[pos].getNode(boardList[pos].getPointer1());
        }
        else {
            //calculate point to list of moves
            return boardList[pos].getNode(boardList[pos].getPointer2());
        }
    }
    else {
        return getNextNode(pos+1, counter-1, listOfMoves);
    }
}






