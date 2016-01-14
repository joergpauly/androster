/********************************************************************
*
*   File: cdatabasemanager.h    Class: CDatabaseManager
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
#ifndef CDATABASEMANAGER_H
#define CDATABASEMANAGER_H

// System-Header
#include <QApplication>
#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QVariant>

// Projekt-Header
#include "cduty.h"
#include "cdutytype.h"
#include "cpersonal.h"

// Definitionen
#define DBFILE   "mr.sqlite"

class CDatabaseManager : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase    m_db;
    QObject*        m_parent;

public:
    // Konstruktor / Destruktor
    explicit CDatabaseManager(QObject *parent = 0);
    ~CDatabaseManager();

    // Public Member
    bool openDb();
    void closeDb();

signals:

public slots:
};

#endif // CDATABASEMANAGER_H
