/********************************************************************
*
*   File: cdownloader.cpp    Class: CDownloader
*
*   This file is part of the MEGA-Series Project.
*   Copyright (C) 2016 Joerg Pauly
*   Created 10.01.2016 by joerg
*   All Rights reserved
*
*   Alle Programme der MEGA-Serie sind Freie Software:
*   Sie können sie unter den Bedingungen
*   der GNU Lesser General Public License, wie von der
*   Free Software Foundation, Version 3 der Lizenz oder
*   (nach Ihrer Option) jeder späteren veröffentlichten
*   Version, weiterverbreiten und/oder modifizieren.
*
*   Dieses Programm wird in der Hoffnung, dass es nützlich
*   sein wird, aber OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt;
*   sogar ohne die implizite Gewährleistung der MARKTFÄHIGKEIT
*   oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
*   Siehe die GNU Lesser General Public License für weitere Details.
*
*   Sie sollten eine Kopie der GNU Lesser General Public License
*   zusammen mit diesem Programm erhalten haben.
*   Wenn nicht, siehe <http://www.gnu.org/licenses/>.
*
********************************************************************/
#include "cdownloader.h"

CDownloader::CDownloader(QObject *parent) : QObject(parent)
{
    m_parent = parent;
}

CDownloader::~CDownloader()
{
    if(m_DbFile)
    {
        m_DbFile->deleteLater();
    }

    if(m_TsFile)
    {
        m_TsFile->deleteLater();
    }
}

void CDownloader::doDownload(bool pSetup = false)
{
    m_Setup = pSetup;
    m_DbFile = new QFile(qApp->applicationDirPath() + "/" + DBFILE);
    m_TsFile = new QFile(qApp->applicationDirPath() + "/" + TSFILE);
    m_ToFile = new QFile(qApp->applicationDirPath() + "/" + TOFILE);

    // Zunächst Timestamp holen
    getTimeStamp();
}

bool CDownloader::checkDb()
{
    QString lFName(qApp->applicationDirPath());
    lFName.append("/");
    lFName.append(DBFILE);
    QFile lFile(lFName);
    return lFile.open(QIODevice::ReadOnly);
}

void CDownloader::dlFinished()
{
    switch(m_retrieveMode)
    {
        case timeStamp:
        {
            // Altes Timestamp sichern
            m_TsFile->open(QIODevice::ReadOnly);
            m_ToFile->open(QIODevice::WriteOnly);
            m_ToFile->write(m_TsFile->readAll());
            m_ToFile->close();
            m_TsFile->close();
            // Neues Timestamp holen
            m_TsFile = new QFile(qApp->applicationDirPath() + "/" + TSFILE);
            m_TsFile->open(QIODevice::WriteOnly);
            m_TsFile->write(m_Reply->readAll());
            m_TsFile->close();
            // Bei Setup sofort Db holen, ansonsten Timestamp vergleichen
            if(m_Setup)
            {
                m_Setup = false;
                getDataBase();
            }
            else
            {
                checkForUpdate();
            }
            break;
        }
        case dataBase:
        {
            m_DbFile->open(QIODevice::WriteOnly);
            m_DbFile->write(m_Reply->readAll());
            m_DbFile->close();
            break;
        }
    }
}

bool CDownloader::getTimeStamp()
{
    m_netMan = new QNetworkAccessManager(this);
    m_retrieveMode = timeStamp;
    QUrl lUrl(QString(FTPURL) + QString(TSFILE));
    lUrl.setUserName(USERNAME);
    lUrl.setPassword(PASSWD);
    m_Request = new QNetworkRequest(lUrl);
    m_Reply = m_netMan->get(*m_Request);
    connect(m_Reply, SIGNAL(finished()), this, SLOT(dlFinished()));
}

bool CDownloader::getDataBase()
{

}

void CDownloader::checkForUpdate()
{
    m_ToFile->open(QIODevice::ReadOnly);
    double lOld = m_ToFile->readAll().toDouble();
    m_TsFile->open(QIODevice::ReadOnly);
    double lNew = m_TsFile->readAll().toDouble();
    if(lOld < lNew)
    {
        getDataBase();
    }
}
