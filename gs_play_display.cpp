#include "gs_play_display.h"

GSPlayDisplay::GSPlayDisplay() { 
	if ( !(myGraphics = new GraphicsComponent()) ) {
		// 
		}
	}

GSPlayDisplay::~GSPlayDisplay() { 
	delete myGraphics;
	}

void GSPlayDisplay::setup() {
	scoreP1 = scoreP2 = "0";
	color = {0xFF, 0xFF, 0xFF};
	}

void GSPlayDisplay::update( int _scoreP1, int _scoreP2 ) {
	scoreP1 = std::to_string(_scoreP1);
	scoreP2 = std::to_string(_scoreP2);
	}

void GSPlayDisplay::render( SDL_Renderer* renderer, TTF_Font* font ) {
	myGraphics->loadString( renderer, font, scoreP1, color );
	myGraphics->drawString( renderer, 
							SDLGraphics::SCREEN_WIDTH/2 - SCORE_OFFSET_X - myGraphics->getWidth(), 
							SCORE_POS_Y );
	myGraphics->loadString( renderer, font, scoreP2, color );
	myGraphics->drawString( renderer, 
							SDLGraphics::SCREEN_WIDTH/2 + SCORE_OFFSET_X, 
							SCORE_POS_Y );

	for (int i = 0; i < SDLGraphics::SCREEN_HEIGHT; i += 20) {
		myGraphics->drawRectangle(  renderer, 
									SDLGraphics::SCREEN_WIDTH / 2 - 2,
									i,
									4,
									12,
									(const Uint8[]){0xFF, 0xFF, 0xFF, 0xFF}
								);
		}
	}
