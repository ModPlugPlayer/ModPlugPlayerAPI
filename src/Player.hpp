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
#include "PlayListDTOs.hpp"
#include <filesystem>

namespace ModPlugPlayer {
    class Player {
    signals:
        /*!
         * \brief open is expected to be emitted when the player opens the corresponding file.
         * \param filePath path of the file to be opened.
         */
        virtual void open(const std::filesystem::path filePath) = 0;

        /*!
         * \brief open is expected to be emitted when the player opens the corresponding playlist item.
         * \param playListItem playlist item to be opened.
         */
        virtual void open(const PlayListItem playListItem) = 0;

        /*!
         * \brief stop
         */
        virtual void stop() = 0;

        /*!
         * \brief stop
         * \param playListItem
         */
        virtual void stop(const PlayListItem playListItem) = 0;

        /*!
         * \brief play
         */
        virtual void play() = 0;

        /*!
         * \brief play
         * \param playListItem
         */
        virtual void play(const PlayListItem playListItem) = 0;

        /*!
         * \brief pause
         */
        virtual void pause() = 0;

        /*!
         * \brief pause
         * \param playListItem
         */
        virtual void pause(const PlayListItem playListItem) = 0;

        /*!
         * \brief resume
         */
        virtual void resume() = 0;

        /*!
         * \brief resume
         * \param playListItem
         */
        virtual void resume(const PlayListItem playListItem) = 0;

        /*!
         * \brief previous
         */
        virtual void previous() = 0;

        /*!
         * \brief next
         * \param playListItem
         */
        virtual void next() = 0;

        /*!
         * \brief changeVolume
         * \param volume
         */
        virtual void changeVolume(const int volume) = 0;

        /*!
         * \brief scrubTime
         * \param position
         */
        virtual void scrubTime(const int position) = 0;

        /*!
         * \brief changeRepeat
         * \param repeat
         */
        virtual void changeRepeat(const ModPlugPlayer::RepeatState repeat) = 0;

        /*!
         * \brief changeEq
         * \param activated
         */
        virtual void changeEq(const bool activated) = 0;

        /*!
         * \brief setAlwaysOnTop
         * \param alwaysOnTop
         */
        virtual void setAlwaysOnTop(const bool alwaysOnTop) = 0;

        /*!
         * \brief hideTitleBar
         * \param hide
         */
        virtual void hideTitleBar(const bool hide) = 0;

        /*!
         * \brief snapToViewPort
         * \param toBeSnappedToViewPort
         */
        virtual void snapToViewPort(const bool toBeSnappedToViewPort) = 0;

        /*!
         * \brief keepStayingInViewPort
         * \param toBeKeptStayingInViewPort
         */
        virtual void keepStayingInViewPort(const bool toBeKeptStayingInViewPort) = 0;

    public:
        /*!
         * \brief getVolume
         * \return
         */
        virtual int getVolume() const = 0;

        /*!
         * \brief isAlwaysOnTop
         * \return
         */
        virtual bool isAlwaysOnTop() const = 0;

        /*!
         * \brief isTitleBarHidden
         * \return
         */
        virtual bool isTitleBarHidden() const = 0;

        /*!
         * \brief isSnapToViewPort
         * \return
         */
        virtual bool isSnapToViewPort() const = 0;

        /*!
         * \brief isKeptStayingInViewPort
         * \return
         */
        virtual bool isKeptStayingInViewPort() const = 0;

    public slots:
        /*!
         * \brief onOpen
         * \param filePath
         */
        virtual void onOpen(const std::filesystem::path filePath) = 0;

        /*!
         * \brief onOpen
         * \param playListItem
         */
        virtual void onOpen(const PlayListItem playListItem) = 0;

        /*!
         * \brief onStop
         */
        virtual void onStop() = 0;

        /*!
         * \brief onStop
         */
        virtual void onStop(const PlayListItem playListItem) = 0;

        /*!
         * \brief onPlay
         */
        virtual void onPlay() = 0;

        /*!
         * \brief onPlay
         * \param playListItem
         */
        virtual void onPlay(const PlayListItem playListItem) = 0;

        /*!
         * \brief onPause
         */
        virtual void onPause() = 0;

        /*!
         * \brief onPause
         */
        virtual void onPause(const PlayListItem playListItem) = 0;

        /*!
         * \brief onResume
         */
        virtual void onResume() = 0;

        /*!
         * \brief onResume
         */
        virtual void onResume(const PlayListItem playListItem) = 0;

        /*!
         * \brief onPrevious
         */
        virtual void onPrevious() = 0;

        /*!
         * \brief onNext
         */
        virtual void onNext() = 0;

        /*!
         * \brief onChangeVolume
         * \param volume
         */
        virtual void onChangeVolume(const int volume) = 0;

        /*!
         * \brief onScrubTime
         * \param position
         */
        virtual void onScrubTime(const int position) = 0;

        /*!
         * \brief onChangeRepeat
         * \param repeat
         */
        virtual void onChangeRepeat(const ModPlugPlayer::RepeatState repeat) = 0;

        /*!
         * \brief onChangeEq
         * \param activated
         */
        virtual void onChangeEq(const bool activated) = 0;

        /*!
         * \brief onSetAlwaysOnTop
         * \param alwaysOnTop
         */
        virtual void onSetAlwaysOnTop(const bool alwaysOnTop) = 0;

        /*!
         * \brief onHideTitleBar
         * \param hide
         */
        virtual void onHideTitleBar(const bool hide) = 0;

        /*!
         * \brief onSetSnapToViewPort
         * \param snapToViewPort
         */
        virtual void onSetSnapToViewPort(const bool snapToViewPort) = 0;

        /*!
         * \brief onSetKeepStayingInViewPort
         * \param keepStayingInViewPort
         */
        virtual void onSetKeepStayingInViewPort(const bool keepStayingInViewPort) = 0;

        /*!
         * \brief onSetSnappingThreshold
         * \param snappingThreshold
         */
        virtual void onSetSnappingThreshold(const int snappingThreshold) = 0;
    };
}

Q_DECLARE_INTERFACE(ModPlugPlayer::Player, "Player")
