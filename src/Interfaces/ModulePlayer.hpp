/*
ModulePlayer interface of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <QObject>
#include <APIStructures.hpp>

namespace ModPlugPlayer::Interfaces {
    class ModulePlayer {
    signals:
        //Request Signals
        virtual void amigaFilterChangeRequested(const AmigaFilter amigaFilter) = 0;
        virtual void interpolationFilterChangeRequested(const ModPlugPlayer::InterpolationFilter interpolationFilter) = 0;

        //Response Signals
        virtual void amigaFilterChanged(const AmigaFilter amigaFilter) = 0;
        virtual void interpolationFilterChanged(const InterpolationFilter interpolationFilter) = 0;

        //Song signals

    public:

    public slots:
        //Signal Handlers


        //Request Signal Handlers
        virtual void onAmigaFilterChangeRequested(const AmigaFilter amigaFilter) = 0;
        virtual void onInterpolationFilterChangeRequested(const InterpolationFilter interpolationFilter) = 0;

        //Response Signal Handlers
        virtual void onRepeatModeChanged(const RepeatMode repeatMode) = 0;

    };
}

Q_DECLARE_INTERFACE(ModPlugPlayer::Interfaces::ModulePlayer, "ModulePlayer")
