/********************************************************************
*
*   File: cdownloader.cpp    Class: %CLASSNAME%
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

}

void CDownloader::doDownload()
{

}

bool CDownloader::checkDb()
{
    QString lFName(qApp->applicationDirPath());
    lFName.append("/");
    lFName.append(DBFILE);
    QFile lFile(lFName);
    return lFile.open(QIODevice::ReadOnly);
}
