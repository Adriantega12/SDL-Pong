#include "player.h"

Player::Player() { }
Player::~Player() { }

void Player::setup(Paddle*& p) { 
	playerPaddle = p;
	}

void Player::handleInput() { 
	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
	if( currentKeyStates[ SDL_SCANCODE_UP ] ){
		playerPaddle->setVelY(-Paddle::PADDLE_SPEED);
		}
	else if( currentKeyStates[ SDL_SCANCODE_DOWN ] ) {
		playerPaddle->setVelY(Paddle::PADDLE_SPEED);
		}
	else if( !( currentKeyStates[ SDL_SCANCODE_UP ] && currentKeyStates[ SDL_SCANCODE_DOWN ] ) ) {
		playerPaddle->setVelY(0);
		}
	}