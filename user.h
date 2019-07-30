#ifndef USER_H
#define USER_H
#include <QDebug>
#include <QTcpSocket>
class User
{
    Q_OBJECT
    QTcpSocket * my_socket{nullptr};
    QTcpSocket * interlocutor_socket{nullptr};
    QString my_ip{};
public:
    QTcpSocket* get_my_socket();
    QTcpSocket* get_my_interlocutor();
    QString get_my_up();
    User();
};

#endif // USER_H
