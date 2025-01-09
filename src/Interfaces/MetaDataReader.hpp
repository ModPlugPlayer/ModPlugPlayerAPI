/*
MetaDataReader base interface of ModPlug Player
Copyright (C) 2025 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include "APIStructures.hpp"

namespace ModPlugPlayer::Interfaces {
    class MetaDataReader {
    public:
        MetaDataReader(const std::filesystem::path &filePath);
        virtual ModPlugPlayer::SongFileInfo getMetaData() = 0;
    protected:
        std::filesystem::path filePath;
    };
}

inline ModPlugPlayer::Interfaces::MetaDataReader::MetaDataReader(const std::filesystem::path &filePath) {
    this->filePath = filePath;
}
