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

#include <QObject>
#include <QPainter>
#include <QRect>
class QPrinter;

class LogViewWidget;

class LogViewExport : public QObject
{
    Q_OBJECT

public:
    explicit LogViewExport(QWidget *parent, LogViewWidget *logViewWidget);

    ~LogViewExport() override;

    void copyToClipboard();

    void fileSave();

    void sendMail();

    void printSelection();

    void printPreview();
Q_SIGNALS:
    void statusBarChanged(const QString &message);

private:
    void printPageNumber(QPainter &painter, QRect &printView, int movement, int page, int margin);

    QWidget *const mParent;

    LogViewWidget *const mLogViewWidget;
    void print(QPrinter *printer);
};

