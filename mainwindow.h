#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QDebug>
#include <QTcpSocket>
#include <QTcpServer>
#include <QVector>
#include <utility>
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
    void redirection(QTcpSocket * target,const char * data);
    void readyRead();
private:
    Ui::MainWindow *ui;
    QTcpServer * server{nullptr};
    QVector<QTcpSocket*> connections;
    QVector<QTcpSocket*> waiting_room;
    QVector<std::pair<QTcpSocket*,QTcpSocket*>> talks;
    bool server_status=false;
};
#endif // MAINWINDOW_H
