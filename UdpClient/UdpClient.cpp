// ======================================================================
//  UdpClient.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtNetwork>
#include <QtGui>
#include "UdpClient.h"

// ----------------------------------------------------------------------
UdpClient::UdpClient(QWidget* pwgt /*=0*/) : QTextEdit(pwgt)
{
    setWindowTitle("UdpClient");

    m_pudp = new QUdpSocket(this);
    m_pudp->bind(2424);
    connect(m_pudp, SIGNAL(readyRead()), SLOT(slotProcessDatagrams()));    
}

// ----------------------------------------------------------------------
void UdpClient::slotProcessDatagrams()
{
    /* Создаём структуру */
    t1 my_struct;
    do
    {
        /* Заполняем структуру зная её размер */
        m_pudp->readDatagram((char*)&my_struct, sizeof(t1));
        qDebug("sizeof = %d \n",(int)sizeof(t1));
        qDebug("a1 = %d \n",my_struct.a1);
        qDebug("q1 = %d \n",my_struct.q1);
        qDebug("a0 = %d \n",my_struct.mas[0].a0);
        qDebug("a1 = %d \n",my_struct.mas[1].a0);
        qDebug("a2 = %d \n",my_struct.mas[2].a0);
        qDebug("a3 = %d \n",my_struct.mas[3].a0);
    } while(m_pudp->hasPendingDatagrams());

}

