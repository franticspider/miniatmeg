//SSMinMiniatmegatron.ino   MiniAtmegatron Arduino sketch
//Copyright (C) 2015  Paul Soulsby
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <avr/pgmspace.h>
#include <math.h>
#include <stdlib.h>

/*Newly ordered #includes */
#include "libMinHardwareBase.h"
#include "libMinEngineBase.h"

  /*Headers for MinEngine in order of error message */
#include "libMidiBase.h"
#include "libStepSequencerBase.h"
#include "libAtmPatchBase.h"
#include "libMasterClock.h"
#include "libMidi.h"



#include "libAtmPatch.h"
#include "libWavetable.h"
#include "libAtmOscillator.h"
#include "libAtmAudio.h"
#include "libEnvelope.h"
#include "libAmplifier.h"
#include "libBiquadFilter.h"

#include "libLfoProgmem.h"
#include "libLfo.h"

#include "libPortamento.h"
#include "libAtmPitch.h"

#include "libStepSequencerProgmem.h"
#include "libStepSequencerBase.h"
#include "libStepSequencer.h"
#include "libWavecrusher.h"
#include "libFlanger.h"
#include "libClipDistortion.h"
#include "libPwm.h"
#include "libMinEngine.h"

#include "libAnalogueControl.h"
#include "libSwitch.h"
#include "libLedRgb.h"
#include "libMinHardware.h"

#include "libMin.h"


Min miniAtmegatron;

void setup()
{
	miniAtmegatron.initialize();
}

void loop()
{
	static unsigned long last_millis;
	unsigned char ticksPassed = millis() - last_millis;
	last_millis += ticksPassed;
	miniAtmegatron.poll(ticksPassed);
}
