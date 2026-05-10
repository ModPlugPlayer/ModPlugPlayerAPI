/*
API Structures of ModPlug Player
Copyright (C) 2022 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <string>
#include <sstream>
#include <filesystem>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>

namespace ModPlugPlayer {
    struct SongInfo {
        std::string songTitle;
        std::string artist;
        std::string songFormat;
        std::string songFormatName;
        size_t songDuration;
    };

    struct SongFileInfo {
        boost::uuids::uuid id = boost::uuids::random_generator()();
        std::filesystem::path filePath;
        SongInfo songInfo;
        bool successful = true;
    };

    enum class PlayingState {
        Playing,
        Paused,
        Stopped
    };

    enum class SongState {
        Loaded,
        NotLoaded,
        Error
    };

    enum class RepeatMode:int {
        NoRepeat = 0,
        RepeatSong = 1,
        LoopSong = 2,
        RepeatPlayList = 3
    };

    inline RepeatMode& operator++(RepeatMode& state, int) {
        switch(state) {
            case RepeatMode::NoRepeat:
                state = RepeatMode::RepeatSong;
                break;
            case RepeatMode::RepeatSong:
                state = RepeatMode::LoopSong;
                break;
            case RepeatMode::LoopSong:
                state = RepeatMode::RepeatPlayList;
                break;
            case RepeatMode::RepeatPlayList:
                state = RepeatMode::NoRepeat;
                break;
        }
        return state;
    }

    enum class InterpolationFilter:int {
        Internal = 0, //default
        NoInterpolation = 1, //(zero order hold)
        LinearInterpolation = 2,
        CubicInterpolation = 4,
        WindowedSincWith8Taps = 8
    };

    inline InterpolationFilter& operator++(InterpolationFilter& state, int) {
        switch(state) {
            case InterpolationFilter::Internal:
                state = InterpolationFilter::NoInterpolation;
                break;
            case InterpolationFilter::NoInterpolation:
                state = InterpolationFilter::LinearInterpolation;
                break;
            case InterpolationFilter::LinearInterpolation:
                state = InterpolationFilter::CubicInterpolation;
                break;
            case InterpolationFilter::CubicInterpolation:
                state = InterpolationFilter::WindowedSincWith8Taps;
                break;
            case InterpolationFilter::WindowedSincWith8Taps:
                state = InterpolationFilter::Internal;
                break;
        }
        return state;
    }

    enum class AmigaFilter:int {
        Auto = 1,
        Amiga500 = 500,
        Amiga1200 = 1200,
        Unfiltered = 0,
        DisablePaulaEmulation = -1
    };

    inline AmigaFilter& operator++(AmigaFilter& state, int) {
        switch(state) {
            case AmigaFilter::Unfiltered:
                state = AmigaFilter::Amiga500;
                break;
            case AmigaFilter::Amiga500:
                state = AmigaFilter::Amiga1200;
                break;
            case AmigaFilter::Amiga1200:
                state = AmigaFilter::DisablePaulaEmulation;
                break;
            case AmigaFilter::DisablePaulaEmulation:
                state = AmigaFilter::Unfiltered;
                break;
            default:
                state = AmigaFilter::DisablePaulaEmulation;
                break;
        }
        return state;
    }

    enum class PlayingMode {
        Song,
        PlayList
    };

    enum class PlugInType {
        InputPlugIn,
        OutputPlugIn,
        DSPPlugIn,
        GeneralPurposePlugIn,
        VisualizationPlugIn
    };
}