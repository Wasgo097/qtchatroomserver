#include "talkthread.h"
TalkThread::TalkThread(QObject * parent):QThread (parent){}
TalkThread::TalkThread(QTcpSocket *fsocket, QTcpSocket *ssocket,QObject * parent):QThread (parent){
    talk.first=fsocket;
    talk.second=ssocket;
}
void TalkThread::run(){
    qDebug()<<"Starting thread";
}
