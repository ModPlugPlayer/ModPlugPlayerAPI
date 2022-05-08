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

namespace ModPlugPlayer {
    enum class Stage {
        PreAlpha,
        Alpha,
        Beta,
        ReleaseCandidate,
        StableRelease
    };

    enum class PlugInType {
        InputPlugIn,
        OutputPlugIn,
        DSPPlugIn,
        GeneralPurposePlugIn,
        VisualizationPlugIn
    };

    enum class AFormat
    {
        FMT_U8, FMT_S8, FMT_U16_LE, FMT_U16_BE, FMT_U16_NE, FMT_S16_LE, FMT_S16_BE, FMT_S16_NE
    };

    enum class Repeat {
        None = 0,
        SingleTrack = 1,
        PlayList = 2
    };

    struct Version {
        unsigned int major = 0;
        unsigned int minor = 0;
        unsigned int release = 0;
        unsigned int patch = 0;
        Stage stage = Stage::StableRelease;
        unsigned int stageRevision = 0;
        inline std::string str();
    };
}

inline std::string ModPlugPlayer::Version::str() {
    std::stringstream version;

    version << major << "." << minor;

    if(patch != 0) {
        version << "." << release << "." << patch;
    }
    else if(release != 0) {
        version << "." << release;
    }

    switch(stage) {
        case Stage::PreAlpha:
            version << " Pre-Alpha";
        break;
        case Stage::Alpha:
            version << " Alpha";
        break;
        case Stage::Beta:
            version << " Beta";
        break;
        case Stage::ReleaseCandidate:
            version << " Release Candidate";
        break;
        default:
        break;
    }

    if(stage != Stage::StableRelease && stageRevision != 0)
        version << " " << stageRevision;

    return version.str();
}
