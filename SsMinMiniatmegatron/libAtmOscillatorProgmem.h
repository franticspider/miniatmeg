//AtmOscillatorProgmem.h  Progmem for Atmegatron Oscillator class
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

#ifndef ATMOSCILLATORPROGMEM_H_
#define ATMOSCILLATORPROGMEM_H_

#include <avr/pgmspace.h>

static const char OSC_WAVETABLE[2][16][32] PROGMEM = {{
	//square
	{-128,-128,-128,-128,-128,-128,-128,-128,-128,-128,-128,-128,-128,-128,-128,-128,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127}, // 0 Pure Square
	{75,89,92,92,92,91,90,89,-11,-21,-24,-25,-26,28,81,85,-2,-14,-16,-17,-17,-17,-17,-17,-119,-126,-128,-128,-127,-69,-16,-10},                        // 1 Octave square (Juno)
	{115,126,81,-2,-122,-105,-90,-67,82,93,104,109,-16,-100,-128,-107,46,58,70,77,-49,-34,-20,-7,7,20,33,43,-84,-69,-54,-37},                          // 2 square 5ths
	{106,127,125,124,123,122,121,121,-36,-47,-46,-46,-46,-45,-45,-45,-44,-44,-43,-43,-43,-42,-42,-42,-41,-41,-41,-40,-40,-40,-39,-35},                 // 3 NES pulse wave
	//saw
	{-128,-121,-113,-105,-97,-89,-81,-73,-65,-57,-49,-41,-33,-25,-17,-9,-1,7,15,23,31,39,47,55,63,71,79,87,95,103,111,119},                            // 4 Pure Saw
	{7,20,31,44,55,67,78,89,100,110,119,127,69,-90,-31,8,-33,-89,-61,-40,-46,-50,-109,-81,-67,-64,-58,-48,-36,-26,-16,-5},                             // 5 buzz saw
	{-128,-123,-108,-89,-69,-48,-28,-7,14,34,22,-26,-9,9,29,47,-29,-15,2,22,41,-5,-22,-5,15,34,54,74,93,99,33,45},                                     // 6 Saw 5ths (Juno)
	{64,81,93,102,111,119,126,121,4,6,12,20,29,38,48,51,-58,-54,-47,-37,-27,-17,-6,0,-128,-127,-120,-112,-102,-92,-81,-64},                            // 7 Octave saw (Juno)
	//sine
	{-26,-61,-92,-110,-122,-128,-117,-119,-86,-92,-42,-58,0,-24,26,0,21,25,26,31,57,50,92,74,117,91,122,89,99,63,48,10},                               // 8 sub sine + square
	{-1,23,47,70,89,105,117,124,127,124,117,105,89,70,47,23,-1,-25,-49,-72,-91,-107,-119,-126,-128,-126,-119,-107,-91,-72,-49,-25},                    // 9 Pure Sine
	{18,47,44,68,109,108,98,121,127,106,94,106,83,40,34,29,-25,-45,-43,-76,-111,-104,-102,-127,-127,-103,-102,-111,-79,-42,-42,-28},                   //10 sine harmonics (ppg)
	{44,57,62,66,72,79,90,120,126,85,69,58,49,42,36,28,-49,-60,-64,-69,-74,-82,-93,-122,-128,-88,-71,-60,-52,-45,-38,-30},                             //11 warped sine
	//pulse
	{-128,7,7,6,6,5,5,4,4,3,3,3,2,2,2,1,1,1,1,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-2,1},                                                                       //12 pulse (CZ101)
	{-54,-36,127,99,-101,-123,30,107,13,-78,-43,43,46,-17,-43,-5,29,12,-19,-18,6,14,-1,-12,-6,6,5,-4,-7,-1,4,1},                                       //13 bassoon (multivox)
	{27,30,25,15,16,10,11,8,11,5,8,3,5,1,6,-1,2,-2,3,-2,1,-3,-1,-2,2,-2,1,-3,0,-19,-128,-52},                                                          //14 bass (multivox)
	//noise
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}                                                                                  //15 Noise (calculated in code)
	},{
	//buzz
	{-100,-65,10,7,-33,-60,-37,1,-22,-84,-45,-10,-19,-17,-53,25,37,13,60,64,-15,65,127,34,9,9,-11,-44,31,42,49,2},                                     // 0 Metal 1
	{93,35,-58,-128,5,24,30,75,44,-72,-39,59,-7,13,10,34,-35,66,77,52,-55,7,21,-31,-66,-55,-43,-104,7,7,-2,-6},                                        // 1 Metal 2
	{12,37,25,25,100,113,120,-36,-59,127,115,99,36,8,18,9,-15,-38,-47,-36,-52,-116,-124,-126,39,58,-119,-103,-83,-14,8,-14},                           // 2 Metal 3
	{119,-16,26,50,66,-71,-52,3,62,15,6,-33,106,5,125,102,-103,-128,-9,-109,32,-9,-17,-62,-4,48,69,-65,-50,-28,16,-114},                               // 3 Metal 4 (PPG)
	//vocal
	{37,-49,31,-62,20,-28,-128,70,86,19,-64,94,4,89,-34,47,15,-114,96,-16,-17,-67,65,55,-70,26,-76,61,-57,-24,10,-77},                                 // 4 Vocal 1
	{44,119,126,111,53,7,-7,2,11,0,-25,-52,-67,-60,-40,-15,15,40,59,64,48,21,-5,-15,-5,4,-11,-58,-115,-128,-118,-43},                                  // 5 Vocal 2
	{-128,-116,-79,-116,-114,-128,-121,-54,18,-11,-15,18,29,16,6,3,-5,-6,-19,-29,-15,20,6,-16,70,117,127,109,104,78,113,110},                          // 6 Vocal 3 (PPG)
	//reed organ
	{28,36,38,38,37,36,33,35,67,44,29,22,17,14,13,13,41,23,12,6,3,1,0,-10,-128,-119,-100,-83,-67,-52,-39,-24},                                         // 7 brass (multivox)
	{-128,-127,-119,-102,-52,-43,10,22,10,28,50,17,-11,-27,-12,25,-27,11,25,8,-20,-52,-28,-11,-23,-10,43,51,101,115,122,127},                          // 8 reed organ (PPG)
	{35,94,118,71,51,84,88,64,27,19,6,-66,-111,-110,-128,-94,-19,48,87,64,62,55,-55,-96,-54,-7,13,-37,-70,-61,-74,-40},                                // 9 elec piano (Logic)
	{69,126,125,120,81,-8,-94,-128,-113,-74,-29,15,58,98,121,105,32,-64,-121,-128,-125,-100,16,118,126,90,-87,65,-19,-125,-123,-64},                   //10 reed
	//resonant
	{-128,24,-119,27,-110,29,-102,30,-93,23,-84,22,-76,22,-67,16,-40,23,-15,30,7,37,25,44,43,47,54,54,63,61,69,56},                                    //11 resonant saw (CZ101)
	//harmonics
	{40,35,-50,-32,43,0,-117,-35,-22,52,11,8,24,15,-31,16,95,94,-128,-70,-10,28,-26,-17,-8,-28,-48,33,51,113,-36,-31},                                 //12 bell (PPG)
	{-29,-39,116,-30,-97,101,-10,-23,-56,88,-16,-128,104,-3,-31,-51,77,36,-115,89,33,-47,-54,66,33,-111,5,73,-48,-71,89,5},                            //13 chord
	{104,120,120,29,-128,-117,-109,30,118,74,87,-72,-74,-54,-62,63,4,71,21,-4,31,-89,-29,-72,-7,102,75,111,-57,-103,-123,-91},                         //14 sine overtones
	{28,86,48,-53,-80,-20,38,61,-18,32,-72,-12,46,-38,-7,50,-2,-1,-34,-53,7,64,75,-26,-103,-42,17,73,127,-97,-93,-32}                                  //15 saw 3rds
}};

#endif /* ATMOSCILLATORPROGMEM_H_ */