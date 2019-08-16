#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "talkthread.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->menuBar->hide();
    ui->statusBar->hide();
    ui->mainToolBar->hide();
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::on_radioButton_clicked(){
    server_status=!server_status;
    if(server_status==true){
        ui->counttalks->setText("Liczba rozmow: 0");
        ui->countusers->setText("Liczba uzytkownikow: 0");
        ui->countwaiting->setText("Liczba oczekujacych: 0");
        server=new QTcpServer(this);
        if(!server->listen(QHostAddress::Any,1234)){
            ui->serverstatus->setText("Serwer error");
        }
        else{
            ui->serverstatus->setText("Serwer on");
            connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
        }
    }
    else{
        ui->serverstatus->setText("Serwer off");
        ui->counttalks->setText("Liczba rozmow: 0");
        ui->countusers->setText("Liczba uzytkownikow: 0");
        ui->countwaiting->setText("Liczba oczekujacych: 0");
        if(server!=nullptr)delete server;
        for(auto &x:connections)delete x;
        connections.clear();
        for(auto &x:waiting_room)delete x;
        waiting_room.clear();
        for(auto&x:talks)delete x;
        talks.clear();
    }
}
void MainWindow::newConnection()
{
    /*
//    connections.last()->write("Witamy\r\n");
//    if(waiting_room.size()==2){
//        talks.push_back(std::make_pair(waiting_room[0],waiting_room[1]));
//        //connect(talks.last().first,SIGNAL(readyRead()),this,SLOT(redirection(talks.last().second,"od 1")));
//        //connect(talks.last().second,SIGNAL(readyRead()),this,SLOT(redirection(talks.last().first,"od 2")));
//        connect(talks.last().first,SIGNAL(readyRead()),this,SLOT(readyRead()));
//        connect(talks.last().second,SIGNAL(readyRead()),this,SLOT(readyRead()));
//        waiting_room.clear();
//    }
    */
    connections.push_back(server->nextPendingConnection());
    waiting_room.push_back(connections.last());
    if(waiting_room.size()==2){
        talks.push_back(new TalkThread(waiting_room[0],waiting_room[1],this));
        waiting_room.clear();
    }
    qDebug()<<"New connection current size of connections = "<<connections.size()<<", current size of waiting room = "<<
              waiting_room.size()<<", current size of talking = "<<talks.size();
}
/*
//void MainWindow::redirection(QTcpSocket * target,const char * data)
//{
//    target->write(data);
//}
//void MainWindow::readyRead(){
////    while(socket->canReadLine()){
////     qDebug()<<socket->readLine().trimmed();
////    }
//    qDebug()<<"Odebrano dane";
////    for(auto &x:connections){
////        x->write("XDDD\r\n");
////    }
//    // e.g. check with member variable _foobarButton
//   QTcpSocket* socket = (QTcpSocket*)sender();
//   // e.g. casting to the class you know its connected with
//   //QTcpSocket* sender = qobject_cast<QTcpSocket*>(sender());
//   //QTcpSocket * sender=qobject_cast<QTcpSocket*>(sender());
////   if( button != NULL )
////   {
////      ...
////   }
//   for(auto&socket_pair:talks){
//        if((*socket_pair.first)==(*socket)){
//            while(socket->canReadLine()){
//                //ui->chat->append(socket->readLine().trimmed());
//                socket_pair.second->write(socket->readLine().trimmed());
//            }
//        }
//        else if(socket_pair.second==socket){
//            while(socket->canReadLine()){
//                //ui->chat->append(socket->readLine().trimmed());
//                socket_pair.first->write(socket->readLine().trimmed());
//            }
//        }
//        else continue;
//   }
//}
*/
