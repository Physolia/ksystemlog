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

#include <QGroupBox>
#include <QHBoxLayout>

#include <KLocalizedString>
#include <KUrlRequester>

#include "fileList.h"
#include "globals.h"
#include "logging.h"

#include "logLevel.h"

#include "authenticationConfiguration.h"
#include "authenticationLogMode.h"

#include "logModeConfigurationWidget.h"

class AuthenticationConfigurationWidget : public LogModeConfigurationWidget
{
    Q_OBJECT

public:
    AuthenticationConfigurationWidget();

    ~AuthenticationConfigurationWidget() override
    {
    }

public Q_SLOTS:

    void saveConfig() override;

    void readConfig() override;

    void defaultConfig() override;

protected:
    bool isValid() const override;

private:
    KUrlRequester *mAuthenticationUrlRequester = nullptr;
    KMessageWidget *mWarningBox = nullptr;
};

