/*
Player interface of ModPlug Player
Copyright (C) 2022 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <QObject>
#include "APIStructures.hpp"

namespace ModPlugPlayer {
    class Player {
    signals:
        virtual void stop() = 0;
        virtual void play() = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;
        virtual void previous() = 0;
        virtual void next() = 0;
        virtual void changeVolume(int volume) = 0;
        virtual void changeRepeat(ModPlugPlayer::RepeatState repeat) = 0;
        virtual void setAlwaysOnTop(bool alwaysOnTop) = 0;
        virtual bool getAlwaysOnTop() const = 0;
        virtual void hideTitleBar(bool hide) = 0;
        virtual bool snapToViewPort(bool toBeSnappedToViewPort) const = 0;
        virtual void keepStayingInViewPort(bool toBeKeptStayingInViewPort) = 0;

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
        virtual void onPrevious() = 0;
        virtual void onNext() = 0;
        virtual void onChangeVolume(int volume) = 0;
        virtual void onChangeRepeat(ModPlugPlayer::RepeatState repeat) = 0;
        virtual void onSetAlwaysOnTop(bool alwaysOnTop) = 0;
        virtual void onHideTitleBar(bool hide) = 0;
        virtual void onSetSnapToViewPort(bool snapToViewPort) = 0;
        virtual void onSetKeepStayingInViewPort(bool keepStayingInViewPort) = 0;
        virtual void onSetSnappingThreshold(int snappingThreshold) = 0;
    };
}

Q_DECLARE_INTERFACE(ModPlugPlayer::Player, "Player")
