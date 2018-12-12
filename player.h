#ifndef _PLAYER_H
#define _PLAYER_H

#include <SDL2/SDL.h>

#include "paddle.h"

class Player {
	private:
		Paddle* playerPaddle;

	public:
		Player();
		~Player();

		void setup(Paddle*&);
		void handleInput();
	};

#endif //_PLAYER_H