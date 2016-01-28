/********************************************************************
*
*   File: cpersonchoice.cpp    Class: CPersonChoice
*
*   This file is part of the MEGA-Series Project.
*   Copyright (C) 2016 Joerg Pauly
*   Created 28.01.2016 by joerg
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
#include "cpersonchoice.h"
#include "ui_cpersonchoice.h"
#include "cmainwindow.h"


CPersonChoice::CPersonChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CPersonChoice)
{
    ui->setupUi(this);
    CPersonalList* lPersList = ((CMainWindow*)m_parent)->PersList();

    for(int i = 0; i < lPersList->count(); i++)
    {
        ui->cmbPersonal->addItem(QString(lPersList->at(i).Name() + ", " + lPersList->at(i).VName()), QVariant(lPersList->at(i).id()));
    }
}

CPersonChoice::~CPersonChoice()
{
    delete ui;
}

void CPersonChoice::on_cmbPersonal_currentIndexChanged(int index)
{
    m_PersID = ui->cmbPersonal->itemData(index, Qt::UserRole).toInt();
}

int CPersonChoice::PersID() const
{
    return m_PersID;
}
