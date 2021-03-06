#ifndef TALKTHREAD_H
#define TALKTHREAD_H
#include <QThread>
#include <QTcpSocket>
#include <utility>
#include <QDebug>
class TalkThread : public QThread
{
    Q_OBJECT
public:
    explicit TalkThread(QObject * parent=nullptr);
    TalkThread(QTcpSocket * fsocket,QTcpSocket * ssocket,QObject * parent=nullptr);
    void run();
public slots:
    void firstread();
    void secondread();
    void quit_talk();
private:
    std::pair<QTcpSocket *,QTcpSocket*> talk;
};
#endif // TALKTHREAD_H
