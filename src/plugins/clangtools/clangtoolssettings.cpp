/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#include "clangtoolssettings.h"

#include "clangtoolsconstants.h"

#include <coreplugin/icore.h>

#include <utils/hostosinfo.h>
#include <utils/qtcassert.h>

#include <QFileInfo>
#include <QThread>

static const char simultaneousProcessesKey[] = "simultaneousProcesses";

namespace ClangTools {
namespace Internal {

ClangToolsSettings::ClangToolsSettings()
{
    readSettings();
}

ClangToolsSettings *ClangToolsSettings::instance()
{
    static ClangToolsSettings instance;
    return &instance;
}

int ClangToolsSettings::savedSimultaneousProcesses() const
{
    return m_savedSimultaneousProcesses;
}

int ClangToolsSettings::simultaneousProcesses() const
{
    return m_simultaneousProcesses;
}

void ClangToolsSettings::setSimultaneousProcesses(int processes)
{
    m_simultaneousProcesses = processes;
}

void ClangToolsSettings::readSettings()
{
    QSettings *settings = Core::ICore::settings();
    settings->beginGroup(QLatin1String(Constants::SETTINGS_ID));

    const int defaultSimultaneousProcesses = qMax(0, QThread::idealThreadCount() / 2);
    m_savedSimultaneousProcesses = m_simultaneousProcesses
            = settings->value(QString(simultaneousProcessesKey),
                              defaultSimultaneousProcesses).toInt();

    settings->endGroup();
}

void ClangToolsSettings::writeSettings()
{
    QSettings *settings = Core::ICore::settings();
    settings->beginGroup(QString(Constants::SETTINGS_ID));
    settings->setValue(QString(simultaneousProcessesKey), m_simultaneousProcesses);

    m_savedSimultaneousProcesses = m_simultaneousProcesses;

    settings->endGroup();
}

} // namespace Internal
} // namespace ClangTools
