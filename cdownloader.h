/********************************************************************
*
*   File: cdownloader.h    Class: %CLASSNAME%
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
#ifndef CDOWNLOADER_H
#define CDOWNLOADER_H

// System-Header
#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QIODevice>


// Makros
#define FTPURL   "ftp://ftp.it-kramer.eu/mmv/brd/"
#define USERNAME "u40207960"
#define PASSWD   "P3rsephone"


class CDownloader : public QObject
{
    Q_OBJECT

private:
    QObject*            m_parent;
    QFile*              m_TsFile;
    QFile*              m_DbFile;
    QNetworkRequest*    m_Request;
    QNetworkReply*      m_Reply;

public:
    explicit CDownloader(QObject *parent = 0);
    ~CDownloader();

    void doDownload();

signals:

public slots:
};

#endif // CDOWNLOADER_H