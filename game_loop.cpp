#include "game_loop.h"

// Procesos
void GameLoop::setup() {
	currentGS->setup();
	sdlGraphics->loadFont( "fonts/advanced_pixel-7.ttf", 50 );
	}

void GameLoop::handleInput() {
	GameState* gs = currentGS->handleInput();
	if ( gs != nullptr ) {
		delete currentGS;
		currentGS = gs;
		currentGS->setup();
		}
	}

void GameLoop::update() {
	currentGS->update();
	}

// Wrapper de render
void GameLoop::preRender() {
	// Limpiar pantalla y lo que sea
	sdlGraphics->clearScreen( (const Uint8[]){0x00, 0x00, 0x00, 0xFF} );

	render();

	// Renderizar a pantalla
	sdlGraphics->render();
	}

void GameLoop::render() {
	currentGS->render( sdlGraphics->getRendererPtr(), sdlGraphics->getFontPtr() );
	}

// Constr y Destr
GameLoop::GameLoop() {
	if ( !( sdlGraphics = new SDLGraphics() ) ) {
		throw GameLoopException("Insuficiencia de memoria al inicializar SDLGraphics.");
		}

	if ( !( sdlInput = new SDLInput() ) ) {
		throw GameLoopException("Insuficiencia de memoria al inicializar SDLInput.");
		}

	//currentGS = new GameStatePlay();
	currentGS = new GameStateMenu();
	}

GameLoop::~GameLoop() {
	delete sdlGraphics;
	delete sdlInput;
	delete currentGS;
	}

// Loop
void GameLoop::loop() {
	//Event handler
	SDL_Event e;
	// Main loop flag
	bool quit = false;

	setup();

	while ( !quit ) {
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 ) {
			//User requests quit
			if( e.type == SDL_QUIT ) {
				quit = true;
				}
			}

		handleInput();
		update();
		preRender();

		SDL_Delay(1000.0/30);
		}
	}