#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
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
    QVector<QTcpSocket *> connections;
    QVector<QTcpSocket *> waiting_room;
    //QVector<MyThread *> talks;
    bool server_status=false;
};
#endif // MAINWINDOW_H
