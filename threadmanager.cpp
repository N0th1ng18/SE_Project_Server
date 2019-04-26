#include "threadmanager.h"

ThreadManager::ThreadManager(quint16 startingPort, int MAX_GAME_THREADS)
{
    this->startingPort = startingPort;
    this->MAX_GAME_THREADS = MAX_GAME_THREADS;

    //Set FreePorts to Default Values
    for(int i=0; i < MAX_GAME_THREADS; i++)
    {
        freePorts.append(true);
    }
}


bool ThreadManager::addGameThread(int gameID)
{
    //Choose port
    quint16 port = 0;
    for(quint16 i=0; i < freePorts.size(); i++)
    {
        if(freePorts.at(i))
        {
            port = startingPort + i;
            freePorts.replace(i, false);
            break;
        }
    }

    //Failed to find open port
    if(port == 0){
        return false;
    }

    //Create Thread
    GameThreadProcesses *thread = new GameThreadProcesses(gameID, port);
    thread->connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));


    //Create instance of GameThread
    GameThread* gameThread = new GameThread(gameID, thread, port);
    gameThreads.append(gameThread);

    //Start Thread
    thread->start();

    return true;
}
bool ThreadManager::removeGameThread(int gameID)
{

}
