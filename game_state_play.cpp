#include "game_state_play.h"

GameStatePlay::GameStatePlay() {
	if ( !( paddle1 = new Paddle() ) ) {
		//throw GameLoopException("Insuficiencia de memoria al inicialziar Paddle.");
		}
	if ( !( paddle2 = new Paddle() ) ) {
		//throw GameLoopException("Insuficiencia de memoria al inicialziar Paddle.");
		}
	if ( !( myBall = new Ball() ) ) {
		//throw GameLoopException("Insuficiencia de memoria al inicialziar Ball.");
		}
	if ( !( player = new Player() ) ) {
		//throw GameLoopException("Insuficiencia de memoria al inicialziar Player.");
		}
	if ( !( enemy = new Enemy() ) ) {
		//throw GameLoopException("Insuficiencia de memoria al inicialziar Enemy.");
		}
	if ( !( display = new GSPlayDisplay() ) ) {
		//
		}
	}

GameStatePlay::~GameStatePlay() {
	delete paddle1;
	delete paddle2;
	delete myBall;
	delete player;
	delete enemy;
	delete display;
	}

void GameStatePlay::setup() {
	scoreP1 = scoreP2 = 0;

	paddle1->setup(50, SDLGraphics::SCREEN_HEIGHT / 2);
	paddle2->setup( SDLGraphics::SCREEN_WIDTH - 50 - Paddle::PADDLE_WIDTH, 
					SDLGraphics::SCREEN_HEIGHT / 2);
	myBall->setup( paddle1, paddle2 );
	player->setup( paddle1 );
	enemy->setup( paddle2, myBall );
	display->setup();
	}

GameState* GameStatePlay::handleInput() {
	player->handleInput();
	return nullptr;
	}

void GameStatePlay::update() {
	paddle1->update();
	paddle2->update();
	myBall->update( scoreP1, scoreP2 );
	enemy->update();
	display->update( scoreP1, scoreP2 );
	}

void GameStatePlay::render( SDL_Renderer* renderer, TTF_Font* font ) {
	paddle1->render( renderer );
	paddle2->render( renderer );
	myBall->render( renderer );
	display->render( renderer, font );
	}
