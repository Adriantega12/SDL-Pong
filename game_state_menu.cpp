#include "game_state_menu.h"

GameStateMenu::GameStateMenu() {
	graphics = new GraphicsComponent();
	}

GameStateMenu::~GameStateMenu() {
	delete graphics;
	}

void GameStateMenu::setup() {

	}

GameState* GameStateMenu::handleInput() {
	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL ); 
	if ( currentKeyStates[ SDL_SCANCODE_SPACE ] ) {
		return new GameStatePlay();
		}

	return nullptr;
	}

void GameStateMenu::update() {

	}

void GameStateMenu::render( SDL_Renderer* renderer, TTF_Font* font ) {
	SDL_Color color = { 255, 255, 255 };
	graphics->loadString( renderer, font, "PONG!", color );
	graphics->drawString( renderer, 
						SDLGraphics::SCREEN_WIDTH/2 - graphics->getWidth() / 2, 
						SDLGraphics::SCREEN_HEIGHT/2 - graphics->getHeight() / 2 - 100 );
	graphics->loadString( renderer, font, "Press SPACE to play!", color );
	graphics->drawString( renderer, 
						SDLGraphics::SCREEN_WIDTH/2 - graphics->getWidth() / 2, 
						SDLGraphics::SCREEN_HEIGHT/2 - graphics->getHeight() / 2 + 100 );
	}