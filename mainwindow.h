#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QDebug>
#include <QTcpSocket>
#include <QTcpServer>
#include <QVector>
#include <utility>
#include "mythread.h"
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_radioButton_clicked();
    void newConnection();
    //void redirection(QTcpSocket * target,const char * data);
    //void readyRead();
private:
    Ui::MainWindow *ui;
    QTcpServer * server{nullptr};
    QVector<std::pair<int,QTcpSocket*>> connections;
    QVector<std::pair<int,QTcpSocket*>> waiting_room;
    QVector<MyThread> talks;
    bool server_status=false;
};
#endif // MAINWINDOW_H
