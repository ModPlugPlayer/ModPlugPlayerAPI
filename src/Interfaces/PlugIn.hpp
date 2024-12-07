/*
Plugin base interface of ModPlug Player
Copyright (C) 2022 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include "APIStructures.hpp"

namespace ModPlugPlayer::Interfaces {
    class PlugIn {
    public:
        inline PlugIn(void * mainWindow,const std::string &fileName);
        virtual Version version() const = 0;                    // plug-in version
        virtual std::string description() const = 0;            // description of plug-in
        virtual std::string uuid() const = 0;                   // plug-in id. each plug-in gets its own.

        inline bool isQtBasedPlugIn() const;
        inline void * getConfigFrame(void * parentWindow);

        virtual void configurationDialog(void * parentWindow) = 0;
        virtual void aboutDialog(void * parentWindow) = 0;

        virtual void init() = 0;	// Called when the plugin is loaded
        virtual void cleanup() = 0;	// Called when the plugin is unloaded
    protected:
        const void * playerMainWindow;                 // player's main window (filled in by the player)
        const std::string plugInFileName;                           // Filled in by the player */
        //HINSTANCE hDllInstance;		// DLL instance handle (filled in by the player)
    };
}

inline ModPlugPlayer::Interfaces::PlugIn::PlugIn(void * playerMainWindow, const std::string &plugInFileName)
    : plugInFileName(plugInFileName), playerMainWindow(playerMainWindow) {
}

inline bool ModPlugPlayer::Interfaces::PlugIn::isQtBasedPlugIn() const {
    return false;
}

inline void * ModPlugPlayer::Interfaces::PlugIn::getConfigFrame(void *) {
    return nullptr;
}
