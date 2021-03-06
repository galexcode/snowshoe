/****************************************************************************
 *   Copyright (C) 2011  Instituto Nokia de Tecnologia (INdT)               *
 *                                                                          *
 *   This file may be used under the terms of the GNU Lesser                *
 *   General Public License version 2.1 as published by the Free Software   *
 *   Foundation and appearing in the file LICENSE.LGPL included in the      *
 *   packaging of this file.  Please review the following information to    *
 *   ensure the GNU Lesser General Public License version 2.1 requirements  *
 *   will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.   *
 *                                                                          *
 *   This program is distributed in the hope that it will be useful,        *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 ****************************************************************************/

#ifndef ApplicationStateTracker_h
#define ApplicationStateTracker_h

#include <QtCore/QObject>
#include <QtCore/QRect>
#include <QtCore/QStringList>
#include <QtCore/QTimer>

class ApplicationStateTracker : public QObject {
    Q_OBJECT
    Q_PROPERTY(QStringList urlsOpened READ urlsOpened WRITE setUrlsOpened NOTIFY urlsOpenedChanged)

public:
    ApplicationStateTracker();
    virtual ~ApplicationStateTracker();

    QRect windowGeometry() const { return m_windowGeometry; }
    void setWindowGeometry(const QRect&);

    QStringList urlsOpened() const { return m_urlsOpened; }
    void setUrlsOpened(const QStringList&);

signals:
    void urlsOpenedChanged();

private slots:
    void saveState();

private:
    Q_DISABLE_COPY(ApplicationStateTracker)

    void loadState();
    void startTimerIfNeeded();

    QTimer m_saveTimer;
    QRect m_windowGeometry;
    QStringList m_urlsOpened;
};

#endif
