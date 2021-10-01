/***************************************************************************
 *   KSystemLog, a system log viewer tool                                  *
 *   SPDX-FileCopyrightText: 2007 Nicolas Ternisien *
 *   nicolas.ternisien@gmail.com                                           *
 *                                                                         *
 *   SPDX-License-Identifier: GPL-2.0-or-later
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 ***************************************************************************/

#pragma once

#include <QList>
#include <QObject>
#include <QStringList>

#include "logFile.h"

class KSystemLogConfig;

class LogModeConfiguration : public QObject
{
    Q_OBJECT

public:
    explicit LogModeConfiguration(QObject *parent = nullptr);

    ~LogModeConfiguration() override;

    LogFile findGenericLogFile(const QString &file);
    QVector<LogFile> findGenericLogFiles(const QStringList &files);

    QVector<LogFile> findNoModeLogFiles(const QStringList &stringList);

protected:
    KSystemLogConfig *mConfiguration = nullptr;
};

