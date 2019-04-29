#include <QCoreApplication>
#include <QTcpSocket>

#include "threadmanager.h"

#include "map.h"
#include "point.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    quint16 STARTINGPORT = 5556;
    int MAX_GAME_THREADS = 5;

    ThreadManager* tm = new ThreadManager(STARTINGPORT, MAX_GAME_THREADS);

    tm->createServerThread();


    /*
     *HOW TO MAP IS DONE!!!!
     *
    Map* map = new Map(":/MapCoord/coordinates.txt");

    Node* startingPosition = map->getHead();

    std::vector<Point*> outList;
    int val = map->movePlayer(startingPosition, 50, outList);

    for(size_t i=0; i < outList.size(); i++)
    {
        qDebug() << i << " | " << val << " : " << outList.at(i)->getX() << " , " << outList.at(i)->getY();
    }
    */

    return a.exec();
}








