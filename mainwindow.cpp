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
//    ui->counttalks->setText("Liczba rozmow: 0");
//    ui->countusers->setText("Liczba uzytkownikow: 0");
//    ui->countwaiting->setText("Liczba oczekujacych: 0");
    server=std::make_shared<QTcpServer>(this);
    if(!server->listen(QHostAddress::Any,1234)){
        ui->serverstatus->setText("Serwer error");
        exit(-1);
    }
    else{
        ui->serverstatus->setText("Serwer on");
        qDebug()<<"Server on";
        connect(server.get(),SIGNAL(newConnection()),this,SLOT(newConnection()));
    }
}
MainWindow::~MainWindow(){
    delete ui;
    for(auto &x:talks)
        x->quit();
}
void MainWindow::newConnection(){
    connections.push_back(std::shared_ptr<QTcpSocket>( server->nextPendingConnection()));
    waiting_room.push_back(connections.last());
    waiting_room.last()->write("Witaj \r\n");
    qDebug()<<"Nowy host";
    if(waiting_room.size()==2){
        talks.push_back(std::make_shared<TalkThread>(waiting_room[0].get(),waiting_room[1].get(),this));
        talks.last()->start();
        waiting_room.clear();
        qDebug()<<"Nowa rozmowa";
    }
    qDebug()<<"New connection current size of connections = "<<connections.size()<<", current size of waiting room = "<<
              waiting_room.size()<<", current size of talking = "<<talks.size();
}
