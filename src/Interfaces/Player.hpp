/*
Player interface of ModPlug Player
Copyright (C) 2022 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <QObject>
#include <APIStructures.hpp>
#include "../PlayListDTOs.hpp"
#include <filesystem>

namespace ModPlugPlayer::Interfaces {
    class Player {
    signals:
        //Request Signals
        virtual void openRequested(const std::filesystem::path filePath) = 0;
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
        virtual void dspStateChangeRequested(const bool activated) = 0;
        virtual void alwaysOnTopStateChangeRequested(const bool alwaysOnTop) = 0;
        virtual void titleBarHidingStateChangeRequested(const bool hide) = 0;
        virtual void snappingToViewPortStateChangeRequested(const bool toBeSnappedToViewPort) = 0;
        virtual void keepingStayingInViewPortStateChangeRequested(const bool toBeKeptStayingInViewPort) = 0;

        //Response Signals
        virtual void loaded(const std::filesystem::path filePath, bool successfull) = 0;
        virtual void loaded(const PlayListItem playListItem, bool successfull) = 0;
        virtual void stopped() = 0;
        virtual void stopped(const PlayListItem playListItem) = 0;
        virtual void playingStarted(SongFileInfo songFileInfo) = 0;
        virtual void playingStarted(const PlayListItem playListItem) = 0;
        virtual void paused() = 0;
        virtual void paused(const PlayListItem playListItem) = 0;
        virtual void resumed() = 0;
        virtual void resumed(const PlayListItem playListItem) = 0;
        virtual void previous() = 0;
        virtual void next() = 0;
        virtual void volumeChanged(const int volume) = 0;
        virtual void timeScrubbed(const int position) = 0;
        virtual void repeatModeChanged(const RepeatMode repeat) = 0;
        virtual void eqStateChanged(const bool activated) = 0;
        virtual void dspStateChanged(const bool activated) = 0;
        virtual void alwaysOnTopStateChanged(const bool alwaysOnTop) = 0;
        virtual void titleBarHidingStateChanged(const bool hide) = 0;
        virtual void snappingToViewPortStateChanged(const bool snapToViewPort) = 0;
        virtual void keepingStayingInViewPortStateChanged(const bool toBeKeptStayingInViewPort) = 0;

        //Song signals
        virtual void elapsedTimeChanged(const int seconds) = 0;
        virtual void trackDurationChanged(const size_t songDurationSeconds) = 0;
        virtual void trackTitleChanged(const QString songTitle) = 0;

    public:
        //Getter Methods
        virtual int getVolume() const = 0;
        virtual bool isAlwaysOnTop() const = 0;
        virtual bool isTitleBarHidden() const = 0;
        virtual bool isSnapToViewPort() const = 0;
        virtual bool isKeptStayingInViewPort() const = 0;

    public slots:
        //Request Signal Handlers
        virtual void onOpenRequested(const std::filesystem::path filePath) = 0;
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
        virtual void onTimeScrubbed(const int position) = 0;

        virtual void onRepeatModeChangeRequested(const RepeatMode repeatMode) = 0;
        virtual void onEqStateChangeRequested(const bool activated) = 0;
        virtual void onDSPStateChangeRequested(const bool activated) = 0;
        virtual void onAlwaysOnTopStateChangeRequested(const bool alwaysOnTop) = 0;
        virtual void onTitleBarHidingStateChangeRequested(const bool hide) = 0;
        virtual void onSnappingToViewPortStateChangeRequested(const bool snapToViewPort) = 0;
        virtual void onKeepingStayingInViewPortStateChangeRequested(const bool keepStayingInViewPort) = 0;
        virtual void onSnappingThresholdChangeRequested(const int snappingThreshold) = 0;


        //Response Signal Handlers
        virtual void onLoaded(const std::filesystem::path filePath, bool successfull) = 0;
        virtual void onLoaded(const PlayListItem playListItem, bool successfull) = 0;
        virtual void onPlayingStarted() = 0;
        virtual void onPlayingStarted(const PlayListItem playListItem) = 0;
        virtual void onStopped() = 0;
        virtual void onStopped(const PlayListItem playListItem) = 0;
        virtual void onPaused() = 0;
        virtual void onPaused(const PlayListItem playListItem) = 0;
        virtual void onResumed() = 0;
        virtual void onResumed(const PlayListItem playListItem) = 0;
        virtual void onRepeatModeChanged(const RepeatMode repeatMode) = 0;
    };
}

Q_DECLARE_INTERFACE(ModPlugPlayer::Interfaces::Player, "Player")
