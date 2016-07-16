//Flanger.cpp  Flanger class (labelled as phaser on synth)
//Copyright (C) 2015  Paul Soulsby info@soulsbysynths.com
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

#include <stdlib.h>
#include <math.h>

#include <avr/pgmspace.h>

#include "libWavetable.h"
#include "libSsHelpers.h"

#include "libFlanger.h"

// default constructor
Flanger::Flanger(unsigned char waveLength)
{
	resizeWavetable(waveLength);
	wavetable_ = new Wavetable(waveLength);
} //Flanger

// default destructor
Flanger::~Flanger()
{
	if(wavetable_!=NULL)
	{
		delete wavetable_;
	}
} //~Flanger

void Flanger::resizeWavetable(unsigned char newWaveLen)
{
	waveLength_ = newWaveLen;
	waveLengthMask_ = newWaveLen - 1;
	scale_ = 256 / waveLength_;
}

void Flanger::setLfoAmount(unsigned char newValue)
{
	lfoAmount_ = newValue;
	if(lfoAmount_==0 && envAmount_==0)
	{
		clearBuffer();
	}
}

void Flanger::setEnvAmount(unsigned char newValue)
{
	envAmount_ = newValue;
	if(lfoAmount_==0 && envAmount_==0)
	{
		clearBuffer();
	}
}

void Flanger::processWavetable(Wavetable& sourceWavetable, char envLevel, char lfoLevel)
{
	unsigned char readpos = 0;
	unsigned char offset = 0;
	static unsigned char writepos = 0;
	int input;
	char output;
	if (lfoAmount_>0 || envAmount_>0)
	{
		unsigned char lfoOffset = ((unsigned int)lfoAmount_+1) * (unsigned char)(lfoLevel + 127) >> 8;
		lfoOffset /= scale_;
		unsigned char envOffset = ((unsigned int)envAmount_+1) * (unsigned char)abs(envLevel) >> 7;
		envOffset /= scale_;
		if(lfoOffset+envOffset>waveLength_)
		{
			offset = waveLength_;
		}
		else
		{
			offset = lfoOffset + envOffset;
		}
		//SHOULD THIS WORKAROUND SHOULD BE DON EIN THE ENGINE, NOT HERE?
		if(offset==0)
		{
			offset = 1;  //THIS IS IMPORTANT AS IT MEANS THE SOUND IS NEVER IN PHASE - musically sounds nicer.
		}
		if(offset>writepos)
		{
			readpos = writepos + (waveLength_ - offset);
		}
		else
		{
			readpos = writepos - offset;
		}
		for(unsigned char i=0;i<sourceWavetable.getWaveLength();++i)
		{
			input = (int)sourceWavetable.getSample(i) + (wavetable_->getSample(readpos)>>fbBs_);
			wavetable_->setSample(writepos,constrainChar(input));
			
			output = (sourceWavetable.getSample(i)>>dryBs_) + (wavetable_->getSample(readpos)>>wetBs_);
			sourceWavetable.setSample(i,output);
			writepos++;
			writepos &= waveLengthMask_;
			readpos++;
			readpos &= waveLengthMask_;
		}
		cleared_ = false;
	}
}
void Flanger::clearBuffer()
{
	if(cleared_==false)
	{
		wavetable_->clearSamples();
		cleared_ = true;
	}
	
}
