/**
 *	@section LICENSE
 *
 *	Copyright (C) 2014 Castlekeep
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *	@section DESCRIPTION
 *
 */

#ifndef KEY_CODES_H
#define KEY_CODES_H

#include <SDL2/SDL.h>

enum class KeyCode
{
	ARROW_LEFT=SDLK_LEFT,
	ARROW_RIGHT=SDLK_RIGHT,
	ARROW_UP=SDLK_UP,
	ARROW_DOWN=SDLK_DOWN,
	SHIFT_LEFT=SDLK_LSHIFT,
	SHIFT_RIGHT=SDLK_RSHIFT,
	CTRL_LEFT=SDLK_RCTRL,
	CTRL_RIGHTSDLK_LCTRL,
	ALT_LEFT=SDLK_LALT,
	ALT_RIGHT=SDLK_RALT,
	TAB=SDLK_TAB,
	ESCAPE=SDLK_ESCAPE,
	SPACE=SDLK_SPACE,
	BACKSPACE=SDLK_BACKSPACE,
	NUM_0=SDLK_0,
	NUN_1=SDLK_1,
	NUM_2=SDLK_2,
	NUM_3=SDLK_3,
	NUM_4=SDLK_4,
	NUM_5=SDLK_5,
	NUM_6=SDLK_6,
	NUM_7=SDLK_7,
	NUM_8=SDLK_8,
	NUM_9=SDLK_9,
	A=SDLK_a,
	B=SDLK_b,
	C=SDLK_c,
	D=SDLK_d,
	E=SDLK_e,
	F=SDLK_f,
	G=SDLK_g,
	H=SDLK_h,
	I=SDLK_i,
	J=SDLK_j,
	K=SDLK_k,
	L=SDLK_l,
	M=SDLK_m,
	N=SDLK_n,
	O=SDLK_o,
	P=SDLK_p,
	Q=SDLK_q,
	R=SDLK_r,
	S=SDLK_s,
	T=SDLK_t,
	U=SDLK_u,
	V=SDLK_v,
	W=SDLK_w,
	X=SDLK_x,
	Y=SDLK_y,
	Z=SDLK_z,
};
#endif


