/*
FFT interface of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <complex>

namespace ModPlugPlayer::Interfaces {
    template<class T> class FFT {
    public:
        virtual void initialize() = 0;
        virtual void execute() = 0;
        virtual void close() = 0;
        ~FFT();
        T *fftInput = nullptr;
        std::complex<T> *fftOutput = nullptr;
    };
}

template<class T> inline ModPlugPlayer::Interfaces::FFT<T>::~FFT(){
    close();
}
