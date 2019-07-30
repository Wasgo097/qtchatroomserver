#include "user.h"
QTcpSocket* User::get_my_socket(){return my_socket;}
QTcpSocket* User::get_my_interlocutor(){return interlocutor_socket;}
QString User::get_my_up(){return my_ip;}
User::User():my_ip("127.0.0.1"),my_socket(new QTcpSocket()){}
