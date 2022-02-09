// ======================================================================
//  UdpServer.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QTextEdit>

class QUdpSocket;

typedef struct
{
    quint8 a0;
    quint8 q0;
}t0;

typedef struct
{
    quint8 a1;
    quint8 q1;
    t0 mas[4];
}t1;

// ======================================================================
class UdpServer : public QTextEdit {
Q_OBJECT
private:
    QUdpSocket* m_pudp;

public:
    UdpServer(QWidget* pwgt = 0);

private slots:
    void slotSendDatagram();
};

