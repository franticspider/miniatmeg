//AnalogueControl.cpp  Hardware analogue control (ie potentiometer)
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

#include "libAnalogueControl.h"

// default constructor
AnalogueControl::AnalogueControl(unsigned char initValue)
{
	value_ = initValue;
	valueLast_ = initValue;
} //AnalogueControl

// default destructor
AnalogueControl::~AnalogueControl()
{
} //~AnalogueControl

bool AnalogueControl::hasChanged(unsigned char ticksPassed)
{
	bool changed = false;

	int diff = abs((int)value_ - valueLast_);
	if(diff>kCtrlMoveThreshold && moving_==false)
	{
		moving_ = true;
		moveTick_ = 0;
	}
	else if (moving_==true)
	{
		moveTick_ += ticksPassed;
		if(moveTick_>=kCtrlMoveTimeOut)
		{
			moving_ = false;
		}
	}
	
	if(moving_==true)
	{
		if(value_!=valueLast_)
		{
			valueLast_ = value_;
			changed = true;
		}
	}
	return changed;
}
