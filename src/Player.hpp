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
        //Request Signals
        virtual void openRequested(const std::filesystem::path filePath) = 0;
        virtual void openRequested(const PlayListItem playListItem) = 0;
        virtual void stopRequested() = 0;
        virtual void stopRequested(const PlayListItem playListItem) = 0;
        virtual void playRequested() = 0;
        virtual void playRequested(const PlayListItem playListItem) = 0;
        virtual void pauseRequested() = 0;
        virtual void pauseRequested(const PlayListItem playListItem) = 0;
        virtual void resumeRequested() = 0;
        virtual void resumeRequested(const PlayListItem playListItem) = 0;
        virtual void previousRequested() = 0;
        virtual void nextRequested() = 0;
        virtual void volumeChangeRequested(const int volume) = 0;
        virtual void timeScrubbingRequested(const int position) = 0;
        virtual void repeatModeChangeRequested(const ModPlugPlayer::RepeatMode repeatMode) = 0;
        virtual void eqStateChangeRequested(const bool activated) = 0;
        virtual void interpolationModeChangeRequested(const ModPlugPlayer::InterpolationMode interpolationMode) = 0;
        virtual void alwaysOnTopStateChangeRequested(const bool alwaysOnTop) = 0;
        virtual void titleBarHidingStateChangeRequested(const bool hide) = 0;
        virtual void snapingToViewPortStateChangeRequested(const bool toBeSnappedToViewPort) = 0;
        virtual void keepingStayingInViewPortStateChangeRequested(const bool toBeKeptStayingInViewPort) = 0;

        //Response Signals
        virtual void loaded(const std::filesystem::path filePath, bool successfull) = 0;
        virtual void loaded(const PlayListItem playListItem, bool successfull) = 0;
        virtual void stopped() = 0;
        virtual void stopped(const PlayListItem playListItem) = 0;
        virtual void playingStarted() = 0;
        virtual void playingStarted(const PlayListItem playListItem) = 0;
        virtual void paused() = 0;
        virtual void paused(const PlayListItem playListItem) = 0;
        virtual void resumed() = 0;
        virtual void resumed(const PlayListItem playListItem) = 0;
        virtual void previous() = 0;
        virtual void next() = 0;
        virtual void volumeChanged(const int volume) = 0;
        virtual void timeScrubbed(const int position) = 0;
        virtual void repeatModeChanged(const ModPlugPlayer::RepeatMode repeat) = 0;
        virtual void eqStateChanged(const bool activated) = 0;
        virtual void interpolationModeChanged(const ModPlugPlayer::InterpolationMode interpolationMode) = 0;
        virtual void alwaysOnTopStateChanged(const bool alwaysOnTop) = 0;
        virtual void titleBarHidingStateChanged(const bool hide) = 0;
        virtual void snappingToViewPortStateChanged(const bool snapToViewPort) = 0;
        virtual void keepingStayingInViewPortStateChanged(const bool toBeKeptStayingInViewPort) = 0;


    public:
        //Getter Methods
        virtual int getVolume() const = 0;
        virtual bool isAlwaysOnTop() const = 0;
        virtual bool isTitleBarHidden() const = 0;
        virtual bool isSnapToViewPort() const = 0;
        virtual bool isKeptStayingInViewPort() const = 0;

    public slots:
        //Signal Handlers
        virtual void onLoaded(const std::filesystem::path filePath, bool successfull) = 0;
        virtual void onLoaded(const PlayListItem playListItem, bool successfull) = 0;

        //Request Signal Handlers
        virtual void onStopRequested() = 0;
        virtual void onStopRequested(const PlayListItem playListItem) = 0;
        virtual void onPlayRequested() = 0;
        virtual void onPlayRequested(const PlayListItem playListItem) = 0;
        virtual void onPauseRequested() = 0;
        virtual void onPauseRequested(const PlayListItem playListItem) = 0;
        virtual void onResumeRequested() = 0;
        virtual void onResumeRequested(const PlayListItem playListItem) = 0;
        virtual void onPreviousRequested() = 0;
        virtual void onNextRequested() = 0;
        virtual void onVolumeChangeRequested(const int volume) = 0;
        virtual void onTimeScrubbingRequested(const int position) = 0;

        virtual void onRepeatModeChangeRequested(const ModPlugPlayer::RepeatMode repeatMode) = 0;
        virtual void onEqStateChangeRequested(const bool activated) = 0;
        virtual void onInterpolationModeChangeRequested(const ModPlugPlayer::InterpolationMode interpolationMode) = 0;
        virtual void onAlwaysOnTopStateChangeRequested(const bool alwaysOnTop) = 0;
        virtual void onTitleBarHidingStateChangeRequested(const bool hide) = 0;
        virtual void onSnappingToViewPortStateChangeRequested(const bool snapToViewPort) = 0;
        virtual void onKeepingStayingInViewPortStateChangeRequested(const bool keepStayingInViewPort) = 0;
        virtual void onSnappingThresholdChangeRequested(const int snappingThreshold) = 0;
    };
}

Q_DECLARE_INTERFACE(ModPlugPlayer::Player, "Player")
