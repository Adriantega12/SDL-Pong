#ifndef _GAME_STATE_MENU_H
#define _GAME_STATE_MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "game_state.h"
#include "game_state_play.h"
#include "sdl_graphics.h"
#include "graphics_component.h"

class GameStateMenu : public GameState {
	private:
		GraphicsComponent* graphics;

	public:
		GameStateMenu();
		~GameStateMenu();

		void setup();
		GameState* handleInput();
		void update();
		void render( SDL_Renderer* = nullptr, TTF_Font* = nullptr );
	};

#endif //_GAME_STATE_MENU_H