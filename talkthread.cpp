#include "talkthread.h"
TalkThread::TalkThread(QObject * parent):QThread (parent){}
TalkThread::TalkThread(QTcpSocket *fsocket, QTcpSocket *ssocket,QObject * parent):QThread (parent){
    talk.first=fsocket;
    talk.second=ssocket;
}
void TalkThread::run(){
    qDebug()<<"Starting thread";
    connect(talk.first,SIGNAL(readyRead()),this,SLOT(secondread()),Qt::DirectConnection);
    connect(talk.second,SIGNAL(readyRead()),this,SLOT(firstread()),Qt::DirectConnection);
    exec();
}
void TalkThread::firstread(){
    qDebug()<<"Pierwszy czyta";
    while(talk.second->canReadLine()){
        talk.first->write(talk.second->readLine());
        qDebug()<<talk.second->readLine();
    }
}

void TalkThread::secondread(){
    qDebug()<<"Drugi czyta";
    while(talk.first->canReadLine()){
        qDebug()<<talk.first->readLine();
        talk.second->write(talk.first->readLine());
    }
}
