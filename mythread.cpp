#include "mythread.h"
MyThread::MyThread(std::pair<int,QTcpSocket*> firstsocket,std::pair<int,QTcpSocket*> secondtsocket,QObject * parent):
    QThread (parent),
    firstsocket(firstsocket),
    secondtsocket(secondtsocket){

}
void MyThread::run(){
    qDebug()<<"Sterting thread";
    socket=new QTcpSocket(this);
    if(!socket->setSocketDescriptor(socket_descriptor)){
        emit this->error(socket->error());
        exit(-1);
        return;
    }
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
    qDebug()<<"New socket is right, id: "<<socket_descriptor;
    exec();
}
void MyThread::readyRead(){
    while(socket->canReadLine()){
        qDebug()<<socket_descriptor<<" can read line "<<socket->readLine().trimmed();
    }
}
void MyThread::disconnected(){
    qDebug()<<socket_descriptor<<" socket is disconnected";
    socket->deleteLater();
    exit(0);
}

void MyThread::error(QAbstractSocket::SocketError socketerror){
    qDebug()<<"Error: "<<socketerror;
}

