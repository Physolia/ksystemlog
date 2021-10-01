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

/**
 * Daemon Log Mode Identifier
 */
#define DAEMON_LOG_MODE_ID "daemonLogMode"

/**
 * Daemon Log Icon
 */
#define DAEMON_MODE_ICON "utilities-terminal"

#include <QList>

#include "logMode.h"
#include "logging.h"

#include "daemonConfiguration.h"
#include "daemonConfigurationWidget.h"
#include "syslogAnalyzer.h"

#include "logModeItemBuilder.h"

class DaemonLogMode : public LogMode
{
    Q_OBJECT

public:
    explicit DaemonLogMode();

    ~DaemonLogMode() override;

    Analyzer *createAnalyzer(const QVariant &options = QVariant()) override;

    QVector<LogFile> createLogFiles() override;
};

