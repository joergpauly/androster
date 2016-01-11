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
    m_DbFile = new QFile(qApp->applicationDirPath() + "/" + DBFILE);
    m_TsFile = new QFile(qApp->applicationDirPath() + "/" + TSFILE);

    // Zunächst Timestamp holen
    getTimeStamp();

    // Bei Setup sofort Db holen, ansonsten Timestamp vergleichen
    if(pSetup)
    {
        getDataBase();
    }
    else
    {
        checkForUpdate();
    }
}

bool CDownloader::checkDb()
{
    QString lFName(qApp->applicationDirPath());
    lFName.append("/");
    lFName.append(DBFILE);
    QFile lFile(lFName);
    return lFile.open(QIODevice::ReadOnly);
}

bool CDownloader::getTimeStamp()
{
   QUrl lUrl(QString(FTPURL) + QString(TSFILE));
}

bool CDownloader::getDataBase()
{

}

void CDownloader::checkForUpdate()
{

}
