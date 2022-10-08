/*
PlayList interface definitions of ModPlug Player
Copyright (C) 2022 Volkan Orhan

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#pragma once
#include <QObject>
#include "PlayListDTOs.hpp"

namespace ModPlugPlayer {
    class PlayList {
    public:
        virtual PlayListItem getCurrentItem() = 0;
    signals:
        virtual void play(const PlayListItem playListItem) = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;
        virtual void stop() = 0;
        virtual void next() = 0;
        virtual void previous() = 0;
        virtual void clear() = 0;
    public slots:
        virtual void onPlay(const PlayListItem playListItem) = 0;
        virtual void onPlay() = 0;
        virtual void onPause() = 0;
        virtual void onResume() = 0;
        virtual void onStop() = 0;
        virtual void onNextSong() = 0;
        virtual void onPreviousSong() = 0;
        virtual void onClear() = 0;
    };
}
