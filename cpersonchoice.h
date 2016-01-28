/********************************************************************
*
*   File: cpersonchoice.h    Class: CPersonChoice
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
#ifndef CPERSONCHOICE_H
#define CPERSONCHOICE_H

#include <QDialog>

namespace Ui {
class CPersonChoice;
}

class CPersonChoice : public QDialog
{
    Q_OBJECT

public:
    explicit CPersonChoice(QWidget *parent = 0);
    ~CPersonChoice();

    int PersID() const;

private slots:
    void on_cmbPersonal_currentIndexChanged(int index);

private:
    Ui::CPersonChoice *ui;
    int m_PersID;
    QWidget* m_parent;
};

#endif // CPERSONCHOICE_H
