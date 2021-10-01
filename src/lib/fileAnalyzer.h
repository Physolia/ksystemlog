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
#include <QString>
#include <QStringList>

#include "globals.h"

#include "logLine.h"

#include "logFile.h"
#include "logViewColumn.h"
#include "logViewColumns.h"

#include "analyzer.h"

class LogFileReader;
class LogMode;

class FileAnalyzer : public Analyzer
{
    Q_OBJECT

public:
    explicit FileAnalyzer(LogMode *logMode);

    ~FileAnalyzer() override;

    void watchLogFiles(bool enabled) override;

    void setLogFiles(const QVector<LogFile> &logFiles) override;

protected:
    virtual LogFileReader *createLogFileReader(const LogFile &logFile) = 0;
    virtual Analyzer::LogFileSortMode logFileSortMode() = 0;

    virtual LogLine *parseMessage(const QString &logLine, const LogFile &originalFile) = 0;

private:
    void deleteLogFiles();

    /**
     * Parse and insert the buffered lines in the model
     * Returns the count of inserted lines
     */
    int insertLines(const QStringList &bufferedLines, const LogFile &logFile, ReadingMode readingMode);

    /**
     * Parse and insert a line in the model
     * Returns false if it was not inserted, true if it was
     */
    bool insertLine(const QString &buffer, const LogFile &originalFile, ReadingMode readingMode);

private Q_SLOTS:
    void logFileChanged(LogFileReader *logFileReader, Analyzer::ReadingMode readingMode, const QStringList &content);

protected:
    QList<LogFileReader *> mLogFileReaders;
};

