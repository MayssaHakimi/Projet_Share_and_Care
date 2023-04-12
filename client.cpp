/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtNetwork>

#include "client.h"
#include "liaison.h"
#include "peermanager.h"

Client::Client()
{
    peerManager = new PeerManager(this);
    peerManager->setServerPort(server.serverPort());
    peerManager->startBroadcasting();

    QObject::connect(peerManager, SIGNAL(newConnection(Liaison*)),
                     this, SLOT(newConnection(Liaison*)));
    QObject::connect(&server, SIGNAL(newConnection(Liaison*)),
                     this, SLOT(newConnection(Liaison*)));
}

void Client::sendMessage(const QString &message)
{
    if (message.isEmpty())
        return;

    QList<Liaison *> liaisons = peers.values();
    foreach (Liaison *liaison, liaisons)
        liaison->sendMessage(message);
}

QString Client::nickName() const
{
    return QString(peerManager->userName()) + '@' + QHostInfo::localHostName()
           + ':' + QString::number(server.serverPort());
}

bool Client::hasConnection(const QHostAddress &senderIp, int senderPort) const
{
    if (senderPort == -1)
        return peers.contains(senderIp);

    if (!peers.contains(senderIp))
        return false;

    QList<Liaison *> liaisons = peers.values(senderIp);
    foreach (Liaison *liaison, liaisons) {
        if (liaison->peerPort() == senderPort)
            return true;
    }

    return false;
}

void Client::newConnection(Liaison *liaison)
{
    liaison->setGreetingMessage(peerManager->userName());

    connect(liaison, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(connectionError(QAbstractSocket::SocketError)));
    connect(liaison, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(liaison, SIGNAL(readyForUse()), this, SLOT(readyForUse()));
}

void Client::readyForUse()
{
    Liaison *liaison = qobject_cast<Liaison *>(sender());
    if (!liaison || hasConnection(liaison->peerAddress(),
                                     liaison->peerPort()))
        return;

    connect(liaison, SIGNAL(newMessage(QString,QString)),
            this, SIGNAL(newMessage(QString,QString)));

    peers.insert(liaison->peerAddress(), liaison);
    QString nick = liaison->name();
    if (!nick.isEmpty())
        emit newParticipant(nick);
}

void Client::disconnected()
{
    if (Liaison *liaison = qobject_cast<Liaison *>(sender()))
        removeConnection(liaison);
}

void Client::connectionError(QAbstractSocket::SocketError /* socketError */)
{
    if (Liaison *liaison = qobject_cast<Liaison *>(sender()))
        removeConnection(liaison);
}

void Client::removeConnection(Liaison *liaison)
{
    if (peers.contains(liaison->peerAddress())) {
        peers.remove(liaison->peerAddress());
        QString nick = liaison->name();
        if (!nick.isEmpty())
            emit participantLeft(nick);
    }
    liaison->deleteLater();
}
