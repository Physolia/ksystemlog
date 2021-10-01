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

#include <KLocalizedString>

#include "fileAnalyzer.h"

#include "acpidLogMode.h"
#include "localLogFileReader.h"
#include "parsingHelper.h"

class AcpidAnalyzer : public FileAnalyzer
{
    Q_OBJECT

public:
    explicit AcpidAnalyzer(LogMode *logMode);

    ~AcpidAnalyzer() override
    {
    }

    LogViewColumns initColumns() override;

protected:
    LogFileReader *createLogFileReader(const LogFile &logFile) override
    {
        return new LocalLogFileReader(logFile);
    }

    Analyzer::LogFileSortMode logFileSortMode() override
    {
        return Analyzer::AscendingSortedLogFile;
    }

    LogLine *parseMessage(const QString &logLine, const LogFile &originalFile) override;
};

