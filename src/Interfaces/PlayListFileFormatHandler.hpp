/*
PlayListFileFormatHandler interface definitions of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#pragma once
#include <QObject>
#include "PlayListDTOs.hpp"
#include <filesystem>

namespace ModPlugPlayer::Interfaces {
    class PlayListFileFormatHandler {
    public:
        virtual std::vector<PlayListItem> loadPlayListFromFile(const std::filesystem::path &path) = 0;
        virtual void savePlayListToFile(const std::vector<PlayListItem> &playListItems, const std::filesystem::path &path) = 0;
    };
}

Q_DECLARE_INTERFACE(ModPlugPlayer::Interfaces::PlayListFileFormatHandler, "PlayListFileFormatHandler")
