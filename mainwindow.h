#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <memory>
namespace Ui {
class MainWindow;
}
class TalkThread;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void newConnection();
    void clear_thread();
    void clear_socket();
private:
    Ui::MainWindow *ui;
    std::shared_ptr<QTcpServer> server;
    QVector<std::shared_ptr<QTcpSocket>> connections;
    QVector<std::shared_ptr<QTcpSocket>> waiting_room;
    QVector<std::shared_ptr<TalkThread>> talks;
    bool server_status=false;
};
#endif // MAINWINDOW_H
