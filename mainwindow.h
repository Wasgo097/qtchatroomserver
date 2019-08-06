#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QDebug>
#include <QTcpSocket>
#include <QTcpServer>
#include <QVector>
#include <utility>
#include <memory>
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
private:
    Ui::MainWindow *ui;
    QTcpServer * server{nullptr};
    QVector<std::shared_ptr<QTcpSocket>> connections;
    QVector<std::shared_ptr<QTcpSocket>> waiting_room;
    QVector<std::unique_ptr<MyThread>> talks;
    bool server_status=false;
};
#endif // MAINWINDOW_H
