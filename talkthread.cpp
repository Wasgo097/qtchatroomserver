#include "talkthread.h"
TalkThread::TalkThread(QObject * parent):QThread (parent){}
TalkThread::TalkThread(QTcpSocket *fsocket, QTcpSocket *ssocket,QObject * parent):QThread (parent){
    talk.first=fsocket;
    talk.second=ssocket;
}
void TalkThread::run(){
    qDebug()<<"Starting thread";
    connect(talk.first,&QTcpSocket::readyRead,this,&TalkThread::secondread,Qt::DirectConnection);
    connect(talk.second,&QTcpSocket::readyRead,this,&TalkThread::firstread,Qt::DirectConnection);
    connect(talk.first,&QTcpSocket::disconnected,this,&TalkThread::quit_talk,Qt::DirectConnection);
    connect(talk.second,&QTcpSocket::disconnected,this,&TalkThread::quit_talk,Qt::DirectConnection);
    exec();
}
void TalkThread::firstread(){
    qDebug()<<"First read";
   // while(talk.second->canReadLine()){
        talk.first->write(talk.second->readLine().trimmed());
        //talk.second->write("XDDDD\r\n");
    //}
}
void TalkThread::secondread(){
    qDebug()<<"Second read";
   // while(talk.first->canReadLine()){
        talk.second->write(talk.first->readLine().trimmed());
        //talk.second->write("XDDDD\r\n");
    //}
}
void TalkThread::quit_talk(){
    talk.second->write("Rozlaczono\r\n");
    talk.first->write("Rozlaczono\r\n");
    this->quit();
}
