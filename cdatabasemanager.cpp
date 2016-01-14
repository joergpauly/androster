/********************************************************************
*
*   File: cdatabasemanager.cpp    Class: CDatabaseManager
*
*   This file is part of the MEGA-Series Project.
*   Copyright (C) 2016 Joerg Pauly
*   Created 11.01.2016 by joerg on PSYS41.PSYS
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
#include "cdatabasemanager.h"

CDatabaseManager::CDatabaseManager(QObject *parent) : QObject(parent)
{
    m_parent = parent;
    QString lFile = qApp->applicationDirPath() + "/" + DBFILE;
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(lFile);
}

CDatabaseManager::~CDatabaseManager()
{
    closeDb();
}

bool CDatabaseManager::openDb()
{
    return m_db.open();
}

void CDatabaseManager::closeDb()
{
    if(m_db.isOpen())
    {
        m_db.close();
    }
}

CPersonalList *CDatabaseManager::personalList(QDate pDate)
{

}
