/*
Player interface of ModPlug Player
Copyright (C) 2022 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <QObject>

class Player {
signals:
    void stop();
    void play();
    void pause();
    void resume();
    void changeVolume(int volume);
    void setAlwaysOnTop(bool alwaysOnTop);
    bool getAlwaysOnTop() const;
    void hideTitleBar(bool hide);
    bool snapToViewPort(bool toBeSnappedToViewPort) const;
    void keepStayingInViewPort(bool toBeKeptStayingInViewPort);

public:
    virtual int getVolume() const = 0;
    virtual bool isAlwaysOnTop() const = 0;
    virtual bool isTitleBarHidden() const = 0;
    virtual bool isSnapToViewPort() const = 0;
    virtual bool isKeptStayingInViewPort() const = 0;

public slots:
    virtual void onStop() = 0;
    virtual void onPlay() = 0;
    virtual void onPause() = 0;
    virtual void onResume() = 0;
    virtual void onChangeVolume(int volume) = 0;
    virtual void onSetAlwaysOnTop(bool alwaysOnTop) = 0;
    virtual void onHideTitleBar(bool hide) = 0;
    virtual void onSetSnapToViewPort(bool snapToViewPort) = 0;
    virtual void onSetKeepStayingInViewPort(bool keepStayingInViewPort) = 0;
};
