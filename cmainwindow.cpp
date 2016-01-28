/********************************************************************
*
*   File: cmainwindow.cpp    Class: CMainWindow
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
#include "cmainwindow.h"
#include "ui_cmainwindow.h"

CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMainWindow)
{
    ui->setupUi(this);
    m_Dl = new CDownloader(this);

    // Nachsehen, ob eine DB-Datei vorhanden ist und
    // falls nicht, downloaden.
    if(!m_Dl->checkDb())
    {
        m_Dl->doDownload(true);
    }

    // Datenbank initialisieren
    m_Db = new CDatabaseManager(this);

    // Personalliste laden
    m_PersList = m_Db->personalList(QDate::currentDate());
}

CMainWindow::~CMainWindow()
{
    delete ui;
    m_Db->deleteLater();
    m_Dl->deleteLater();
}

CDatabaseManager *CMainWindow::Db() const
{
    return m_Db;
}

void CMainWindow::on_actionAktualisieren_triggered()
{
    m_Dl->doDownload(false);
}

void CMainWindow::on_actionDB_Test_triggered()
{
    CPersonalList* lList = m_Db->personalList(QDate::currentDate());
    int i = lList->count();
}

void CMainWindow::on_actionDienstplan_f_r_triggered()
{
    CPersonChoice lDlg;

    if(lDlg.exec() == QDialog::Accepted)
    {
        m_ActUser = new CPersonal(lDlg.PersID());
    }
    lDlg.close();
}

CPersonalList *CMainWindow::PersList() const
{
    return m_PersList;
}
