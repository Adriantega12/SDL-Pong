#ifndef _GAME_STATE_PLAY
#define _GAME_STATE_PLAY

#include <SDL2/SDL.h>

#include "sdl_graphics.h"
#include "game_state.h"
#include "paddle.h"
#include "ball.h"
#include "player.h"
#include "enemy.h"
#include "gs_play_display.h"

class GameStatePlay : public GameState {
	private:
		Paddle* paddle1;
        Paddle* paddle2;
        Ball* myBall;
        Player* player;
        Enemy* enemy;
        GSPlayDisplay* display;

        int scoreP1;
        int scoreP2;

	public:
		GameStatePlay();
		~GameStatePlay();

		void setup();
		GameState* handleInput();
		void update();
		void render( SDL_Renderer* = nullptr, TTF_Font* = nullptr );
	};

#endif //_GAME_STATE_PLAY