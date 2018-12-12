#ifndef _GS_PLAY_DISPLAY_H
#define _GS_PLAY_DISPLAY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "sdl_graphics.h"
#include "graphics_component.h"

class GSPlayDisplay {
	private:
		GraphicsComponent* myGraphics;

		std::string scoreP1;
		std::string scoreP2;

		SDL_Color color;

	public:
		static const int SCORE_POS_Y = 50;
		static const int SCORE_OFFSET_X = 140;

		GSPlayDisplay();
		~GSPlayDisplay();

		void setup();
		void update( int = 0, int = 0 );
		void render( SDL_Renderer*, TTF_Font* );
	};

#endif //_GS_PLAY_DISPLAY_H