/*
PlayList DTO definitions of ModPlug Player
Copyright (C) 2022 Volkan Orhan

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#pragma once
#include <QString>
#include <filesystem>
#include <boost/uuid/uuid.hpp>

namespace ModPlugPlayer {
    struct PlayListItem {
        boost::uuids::uuid id;
        size_t itemNumber = 0;
        QString format;
        QString title;
        std::filesystem::path filePath;
        size_t duration = 0;
    };
}

using PlayListItems = QList<ModPlugPlayer::PlayListItem>;
