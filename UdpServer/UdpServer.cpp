// ======================================================================
//  UdpServer.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtNetwork>
#include <QtGui>
#include "UdpServer.h"
#include <QDebug>


// ----------------------------------------------------------------------
UdpServer::UdpServer(QWidget* pwgt /*=0*/) : QTextEdit(pwgt)
{
    setWindowTitle("UdpServer");

    m_pudp = new QUdpSocket(this);


    QTimer* ptimer = new QTimer(this);
    ptimer->setInterval(1500);
    ptimer->start();
    connect(ptimer, SIGNAL(timeout()), SLOT(slotSendDatagram()));


}

// ----------------------------------------------------------------------
void UdpServer::slotSendDatagram()
{

    /* Создаём указатель на струтуру. Необходим именно он для отправки */
    t1 *m_struct = new t1;
    m_struct->a1 = 2;
    m_struct->q1 = 15;
    m_struct->mas[0].a0 = 10;
    m_struct->mas[1].a0 = 11;
    m_struct->mas[2].a0 = 12;
    m_struct->mas[3].a0 = 13;
    /* Отправлять будем по прежнему как QByteArray */
    QByteArray str;
    /* Необходимо указать размер структуры */
    str.append((char*)m_struct, sizeof(t1));
    qDebug("size struct = %d str=%d \n",(int)sizeof(t1),(int)sizeof(str));
    qDebug("m_struct->mas[0].a0= %d \n",m_struct->mas[0].a0);
    qDebug("m_struct->mas[1].a0= %d \n",m_struct->mas[1].a0);
    qDebug("m_struct->mas[2].a0= %d \n",m_struct->mas[2].a0);
    qDebug("m_struct->mas[3].a0= %d \n",m_struct->mas[3].a0);
    /* Отправляем пакет */
    m_pudp->writeDatagram(str, QHostAddress::LocalHost, 2424);
     delete m_struct;
}


