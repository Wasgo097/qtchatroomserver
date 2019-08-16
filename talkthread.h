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
    inline TalkThread(QTcpSocket * fsocket,QTcpSocket * ssocket,QObject * parent=nullptr);
    void run();
private:
    std::pair<QTcpSocket *,QTcpSocket*> talk;
};
#endif // TALKTHREAD_H
