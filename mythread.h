#ifndef MYTHRED_H
#define MYTHRED_H
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int id,QObject * parent=nullptr);
    void run();
private:
    QTcpSocket* socket{nullptr};
    int socket_descriptor{0};
private slots:
    void readyRead();
    void disconnected();
signals:
    inline void error(QTcpSocket::SocketError socketerror);
};
#endif // MYTHRED_H
