/********************************************************************
*
*   File: cmainwindow.h    Class: CMainWindow
*
*   This file is part of the MEGA-Series Project.
*   Copyright (C) 2016 Joerg Pauly
*   Created 06.01.2016 by joerg
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
#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

// System-Header
#include <QMainWindow>
#include <QFile>
#include <QString>

// Projekt-Header
#include "cdownloader.h"
#include "cdatabasemanager.h"
#include "cpersonallist.h"
#include "cpersonchoice.h"
#include "cpersonal.h"

namespace Ui {
class CMainWindow;
}

class CMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    CDownloader*        m_Dl;
    CDatabaseManager*   m_Db;
    CPersonalList*      m_PersList;
    CPersonal*          m_ActUser;

public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();

    CDatabaseManager *Db() const;    
    CPersonalList *PersList() const;

private slots:
    void on_actionAktualisieren_triggered();
    void on_actionDB_Test_triggered();
    void on_actionDienstplan_f_r_triggered();

private:
    Ui::CMainWindow *ui;


};

#endif // CMAINWINDOW_H
