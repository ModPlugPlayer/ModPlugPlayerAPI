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

namespace ModPlugPlayer::Interfaces {
    class PlayList {
    public:
        /*!
         * \brief getCurrentItem gets currently loaded item of the playlist.
         * \return currently loaded item of the playlist.
         */
        virtual PlayListItem getCurrentItem() = 0;
    signals:
        /*!
         * \brief metaDataRequested is expected to be emitted when an item is added to playlist or emitted for each item when playlist is loaded from file.
         * \param playListItem
         */
        virtual void metaDataRequested(const PlayListItem playListItem) = 0;

        /*!
         * \brief loadRequested is expected to be emitted by onNextSong or onPreviousSong when next or previous item is requested.
         * \param playListItem
         */
        virtual void loadRequested(const PlayListItem playListItem) = 0;

        /*!
         * \brief playRequested is expected to be emitted when an item is double clicked or an item's play button is pressed
         * \param playListItem
         */
        virtual void playRequested(const PlayListItem playListItem) = 0;

        /*!
         * \brief pauseRequested is expected to be emitted when pause button of an playlist item is pressed.
         */
        virtual void pauseRequested(const PlayListItem playListItem) = 0;

        /*!
         * \brief resumeRequested is expected to be emitted when resume button of an playlist item is pressed.
         */
        virtual void resumeRequested(const PlayListItem playListItem) = 0;

        /*!
         * \brief stopRequested is expected to be emitted when the playlist needs the player to stop the song.
         * This signal is not used currently since there is not any stop button on playlist items.
         */
        virtual void stopRequested(const PlayListItem playListItem) = 0;

        /*!
         * \brief repeatRequested is expected to be emitted when repeat mode is needed to be changed.
         * \param repeatMode represents the repeat mode that is needed to be set. Possible values: None, SingleTrack, PlayList.
         */
        virtual void repeatRequested(const RepeatMode repeatMode) = 0;

        /*!
         * \brief clearPlayListRequested is expected to be emitted when playlist is needed to be cleared.
         */
        virtual void clearPlayListRequested() = 0;

        /*!
         * \brief horizontalScrollBarVisibilityChanged is expected to be emitted when horizontal scrollbar becomes visible or invisible.
         * \param isVisible is set to true if scrollbar is visible, false othervise.
         */
        virtual void horizontalScrollBarVisibilityChanged(bool isVisible) = 0;

        /*!
         * \brief verticalScrollBarVisibilityChanged is expected to be emitted when vertical scrollbar becomes visible or invisible.
         * \param isVisible is set to true if scrollbar is visible, false othervise.
         */
        virtual void verticalScrollBarVisibilityChanged(bool isVisible) = 0;
    public slots:
        /*!
         * \brief onMetaDataObtained is expected to be triggered when the meta data of the playlist item is obtained by the player.
         * When an item is added to the playlist, playlist issues metaDataRequested signal, and the related component (player or
         * a component related to metadata reading) obtains the meta data, and then the related component issues metaDataObtained signal.
         * onMetaDataObtained slot is expected to be connected another component's metaDataObtained signal.
         * \param playListItem
         */
        virtual void onMetaDataObtained(const PlayListItem playListItem) = 0;

        /*!
         * \brief onLoaded is expected to be triggered after the player loads the corresponding playlist item.
         * Expected to make the corresponding playlist item on the playlist is shown as loaded (eg. showing it in bold fonts, etc.),
         * and to make the previously opened item of the playlist unopened.
         * \param playListItem
         * \param successfull
         */
        virtual void onLoaded(const PlayListItem playListItem, bool successfull) = 0;

        /*!
         * \brief onPlayingStarted is expected to be triggered when the player starts to play the corresponding playlist item.
         * Expected to make the corresponding playlist item on the playlist is shown as open and playing
         * (eg. showing it in bold fonts, making its icon as playing, etc.), and to make the previously opened item of the playlist unopened.
         * \param playListItem
         */
        virtual void onPlayingStarted(const PlayListItem playListItem) = 0;

        /*!
         * \brief onPaused is expected to be triggered when the player pauses the corresponding playlist item.
         * Expected to make the corresponding playlist item on the playlist is shown as paused.
         */
        virtual void onPaused(const PlayListItem playListItem) = 0;

        /*!
         * \brief onResumed is expected to be triggered when the player resumes the corresponding playlist item.
         * Expected to make the corresponding playlist item on the playlist is shown as playing.
         */
        virtual void onResumed(const PlayListItem playListItem) = 0;

        /*!
         * \brief onStopped is expected to be triggered when the player stops the corresponding playlist item.
         * Expected to make the corresponding playlist item on the playlist is shown as stopped.
         */
        virtual void onStopped(const PlayListItem playListItem) = 0;

        /*!
         * \brief onNextRequested is expected to make the playlist to emit open signal with the next playlist item.
         */
        virtual void onNextRequested() = 0;

        /*!
         * \brief onPreviousRequested is expected to make the playlist to emit open signal with the previous playlist item.
         */
        virtual void onPreviousRequested() = 0;

        /*!
         * \brief onClearPlayList is expected to clear the playlist, and to make the player stop and unload the current song.
         */
        virtual void onClearPlayListRequested() = 0;

        /*!
         * \brief onRepeatModeChanged is expected to handle new playlist state when playlist state is changed.
         * \param repeatMode represents the repeat mode that is needed to be set.
         * Possible values: NoRepeat, RepeatTrack, LoopTrack, RepeatPlayList.
         */
        virtual void onRepeatModeChanged(const RepeatMode repeatMode) = 0;
    };
}

Q_DECLARE_INTERFACE(ModPlugPlayer::Interfaces::PlayList, "PlayList")
