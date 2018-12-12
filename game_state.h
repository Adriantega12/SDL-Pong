#ifndef _GAME_STATE_H
#define _GAME_STATE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class GameState {
	protected:
	public:
		GameState() {}
		~GameState() {}

		virtual void setup() = 0;
		virtual GameState* handleInput() = 0;
		virtual void update() = 0;
		virtual void render( SDL_Renderer* = nullptr, TTF_Font* = nullptr ) = 0;
	};

#endif //_GAME_STATE_H