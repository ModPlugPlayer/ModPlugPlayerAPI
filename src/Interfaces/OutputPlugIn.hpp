/*
Output Plugin interface of ModPlug Player
Copyright (C) 2022 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once
#include <APIStructures.hpp>
#include "PlugIn.hpp"

namespace ModPlugPlayer::Interfaces {
class OutputPlugIn : public PlugIn {
    public:
        ///
        /// \brief open
        /// \param sampleRate
        /// \param numChannels
        /// \param bitsPerSamp
        /// \param bufferLen must be in ms. 0 to use defaults.
        /// \param preBuffer must be in ms and must be <= bufferlen. 0 to use defaults.
        /// \return max latency in ms (0 for diskwriters, etc)
        ///
        int open(int sampleRate, int numChannels, int bitsPerSamp, int bufferLen, int preBuffer);
            // returns >=0 on success, <0 on failure

        // NOTENOTENOTE: bufferlenms and prebufferms are ignored in most if not all output plug-ins.
        //    ... so don't expect the max latency returned to be what you asked for.
        // returns
        // bufferlenms and prebufferms
        // prebufferms
        // pass bufferlenms==-666 to tell the output plugin that it's clock is going to be used to sync video
        //   out_ds turns off silence-eating when -666 is passed


        int open(AFormat fmt, int rate, int nch);	/* Open the device, if the device can't handle the given
                                       parameters the plugin is responsible for downmixing
                                       the data to the right format before outputting it */


        void close();	// close the ol' output device.

        int write(void *buf, int len);
            // 0 on success. Len == bytes to write (<= 8192 always). buf is straight audio data.
            // 1 returns not able to write (yet). Non-blocking, always.

        int canWrite();	// returns number of bytes possible to write at a given time.
            // Never will decrease unless you call Write (or Close, heh)

        bool isPlaying(); // returns true if output is still going or if data in buffers waiting to be
            // written (i.e. closing while IsPlaying() returns true would truncate the song)

        bool pause(bool pause); // returns previous pause state

        void setVolume(unsigned char volume); // volume is 0-255
        unsigned char getVolume(); // volume is 0-255
        void setPan(int pan); // pan is -128 to 128
        int getPan(); // pan is -128 to 128

        void flush(int t);	// flushes buffers and restarts output at time t (in ms)
            // (used for seeking)

        int getOutputTime(); // returns played time in MS
        int getWrittenTime(); // returns time written in MS (used for synching up vis stuff)

    };
}
