#ifndef MYTHRED_H
#define MYTHRED_H
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <utility>
class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(std::pair<int,QTcpSocket *> firstsocket,std::pair<int,QTcpSocket*> secondtsocket,QObject * parent=nullptr);
    void run();
private:
    QTcpSocket* socket{nullptr};
    int socket_descriptor{0};
    std::pair<int,QTcpSocket *> firstsocket;
    std::pair<int,QTcpSocket *> secondtsocket;
private slots:
    //void readyRead();
    //void disconnected();
signals:
    inline void error(QTcpSocket::SocketError socketerror);
};
#endif // MYTHRED_H
