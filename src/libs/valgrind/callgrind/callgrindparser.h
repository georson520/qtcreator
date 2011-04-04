/**************************************************************************
**
** This file is part of Qt Creator Instrumentation Tools
**
** Copyright (c) 2011 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** No Commercial Usage
**
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**************************************************************************/

#ifndef LIBVALGRIND_CALLGRIND_PARSER_H
#define LIBVALGRIND_CALLGRIND_PARSER_H

#include "../valgrind_global.h"

#include <QObject>

QT_BEGIN_NAMESPACE
class QIODevice;
QT_END_NAMESPACE

namespace Valgrind {
namespace Callgrind {

class ParseData;

/**
 * Parser for Valgrind --tool=callgrind output
 * most of the format is documented at http://kcachegrind.sourceforge.net/html/CallgrindFormat.html
 *
 * FIXME: most length asserts are not correct, see documentation 1.2:
 * "If a cost line specifies less event counts than given in the "events" line,
 * the rest is assumed to be zero."
 *
 */
class VALGRINDSHARED_EXPORT Parser : public QObject {
    Q_OBJECT
public:
    explicit Parser(QObject *parent=0);
    ~Parser();

    // get and take ownership of the parsing results. If this method is not called the repository
    // will be destroyed when the parser is destroyed. Subsequent calls return null.
    ParseData *takeData();

signals:
    void parserDataReady();

public Q_SLOTS:
    void parse(QIODevice *stream);

private:
    Q_DISABLE_COPY(Parser)

    class Private;
    Private *const d;
};

} // Callgrind
} // Valgrind

#endif //LIBVALGRIND_CALLGRIND_PARSER_H
