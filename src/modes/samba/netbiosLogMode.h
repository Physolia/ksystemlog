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
 * Netbios Log Mode Identifier
 */
#define NETBIOS_LOG_MODE_ID "netbiosLogMode"

/**
 * Netbios Log Icon
 */
#define NETBIOS_MODE_ICON "folder-remote"

#include <QList>

#include "logFile.h"

#include "logMode.h"

class SambaConfiguration;
class SambaConfigurationWidget;
class SambaItemBuilder;

class NetbiosLogMode : public LogMode
{
    Q_OBJECT

public:
    explicit NetbiosLogMode(QSharedPointer<SambaConfiguration> &sambaConfiguration,
                            SambaConfigurationWidget *sambaConfigurationWidget,
                            SambaItemBuilder *itemBuilder);

    ~NetbiosLogMode() override;

    Analyzer *createAnalyzer(const QVariant &options = QVariant()) override;

    QVector<LogFile> createLogFiles() override;
};

