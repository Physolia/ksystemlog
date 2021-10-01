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

#include "multipleActions.h"

#include <QAction>

#include "logging.h"

MultipleActions::MultipleActions(const QIcon &icon, const QString &text, QObject *parent)
{
    mAction = new KActionMenu(icon, text, parent);
}

MultipleActions::~MultipleActions()
{
    delete mAction;
}

QList<QAction *> MultipleActions::innerActions()
{
    return mActions;
}

QAction *MultipleActions::actionMenu()
{
    return mAction;
}

void MultipleActions::addInnerAction(QAction *innerAction, bool addToMenu, bool addToInnerActionsList)
{
    if (addToMenu) {
        mAction->addAction(innerAction);
    }

    if (addToInnerActionsList) {
        mActions.append(innerAction);
    }
}
