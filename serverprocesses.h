#ifndef SERVERPROCESSES_H
#define SERVERPROCESSES_H


#include <QTcpServer>
#include "gamethreadprocesses.h"

class serverProcesses : public QTcpServer
{
    Q_OBJECT
public:
    explicit serverProcesses(int serverType = 0, QObject *parent = nullptr);
    void startServer(quint16 port);
signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);

private:
    int serverType;

    void processMessage(QString message);



};

#endif // SERVER_H
