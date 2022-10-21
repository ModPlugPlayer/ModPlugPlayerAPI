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
#include "APIStructures.hpp"

namespace ModPlugPlayer {
    class PlayList {
    public:
        /*!
         * \brief getCurrentItem gets currently loaded item of the playlist.
         * \return currently loaded item of the playlist.
         */
        virtual PlayListItem getCurrentItem() = 0;
    signals:
        /*!
         * \brief requestMetaData is expected to be emitted when an item is added to playlist or emitted for each item when playlist is loaded from file.
         * \param playListItem
         */
        virtual void requestMetaData(const PlayListItem playListItem) = 0;

        /*!
         * \brief open is expected to be emitted by onNextSong or onPreviousSong when next or previous item is requested.
         * \param playListItem
         */
        virtual void open(const PlayListItem playListItem) = 0;

        /*!
         * \brief play is expected to be emitted when an item is double clicked or an item's play button is pressed
         * \param playListItem
         */
        virtual void play(const PlayListItem playListItem) = 0;

        /*!
         * \brief pause is expected to be emitted when pause button of an playlist item is pressed.
         */
        virtual void pause(const PlayListItem playListItem) = 0;

        /*!
         * \brief resume is expected to be emitted when resume button of an playlist item is pressed.
         */
        virtual void resume(const PlayListItem playListItem) = 0;

        /*!
         * \brief stop is expected to be emitted when the playlist needs the player to stop the song.
         * This signal is not used currently since there is not any stop button on playlist items.
         */
        virtual void stop(const PlayListItem playListItem) = 0;

        /*!
         * \brief repeat is expected to be emitted when repeat state is needed to be changed.
         * \param repeatState represents the repeat state that is needed to be set. Possible values: None, SingleTrack, PlayList.
         */
        virtual void repeat(const RepeatState repeatState) = 0;

    public slots:
        /*!
         * \brief onMetaData
         * \param playListItem
         */
        virtual void onMetaData(const PlayListItem playListItem) = 0;

        /*!
         * \brief onOpen is expected to be triggered when the player opens the corresponding playlist item.
         * Expected to make the corresponding playlist item on the playlist is shown as open (eg. showing it in bold fonts, etc.),
         * and to make the previously opened item of the playlist unopened.
         * \param playListItem
         */
        virtual void onOpen(const PlayListItem playListItem) = 0;

        /*!
         * \brief onPlay is expected to be triggered when the player plays the corresponding playlist item.
         * Expected to make the corresponding playlist item on the playlist is shown as open and playing
         * (eg. showing it in bold fonts, making its icon as playing, etc.), and to make the previously opened item of the playlist unopened.
         * \param playListItem
         */
        virtual void onPlay(const PlayListItem playListItem) = 0;

        /*!
         * \brief onPause is expected to be triggered when the player pauses the corresponding playlist item.
         * Expected to make the corresponding playlist item on the playlist is shown as paused.
         */
        virtual void onPause(const PlayListItem playListItem) = 0;

        /*!
         * \brief onResume is expected to be triggered when the player resumes the corresponding playlist item.
         * Expected to make the corresponding playlist item on the playlist is shown as playing.
         */
        virtual void onResume(const PlayListItem playListItem) = 0;

        /*!
         * \brief onStop is expected to be triggered when the player stops the corresponding playlist item.
         * Expected to make the corresponding playlist item on the playlist is shown as stopped.
         */
        virtual void onStop(const PlayListItem playListItem) = 0;

        /*!
         * \brief onNextSong is expected to make the playlist to emit open signal with the next playlist item.
         */
        virtual void onNextSong() = 0;

        /*!
         * \brief onPreviousSong is expected to make the playlist to emit open signal with the previous playlist item.
         */
        virtual void onPreviousSong() = 0;

        /*!
         * \brief onClear is expected to clear the playlist, and to make the player stop and unload the current song.
         */
        virtual void onClear() = 0;

        /*!
         * \brief onRepeat is expected to handle new playlist state when playlist state is changed.
         * \param repeatState represents the repeat state that is needed to be set. Possible values: None, SingleTrack, PlayList.
         */
        virtual void onRepeat(const RepeatState repeatState) = 0;
    };
}

Q_DECLARE_INTERFACE(ModPlugPlayer::PlayList, "PlayList")
