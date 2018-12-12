#include "sdl_graphics.h"

// Constructors
SDLGraphics::SDLGraphics() { 
    window = nullptr;
    renderer = nullptr;
    font = nullptr;
    init();
    }

SDLGraphics::~SDLGraphics() { 
    close();
    }

// System enter and exit
void SDLGraphics::init() {
	// Inicializar SDL
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0) {
        // Fallo al inicializar SDL
        throw SDLGraphicsException("Módulo de SDL no pudo ser inicializado.");
        }

    // Filtrado de texturas a linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
        // Advertencia
        std::cout << "¡Advertencia! Filtrado lineal de textura no disponible." << std::endl;
        }

    //Initialize SDL_ttf 
    if( TTF_Init() == -1 ) {
        throw SDLGraphicsException("Módulo de TTF no pudo ser inicializado.");
        }

    // Crear ventana
    if ( !(  window = SDL_CreateWindow( "Pong!",
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT,
                                   SDL_WINDOW_SHOWN ) ) ) {
        throw SDLGraphicsException("SDL_Window no pudo ser inicializada.");
        }

    // Inicializar renderer
    if ( !( renderer = SDL_CreateRenderer( window, - 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ) ) ) {
        // Error, renderer no pudo ser creado
        throw SDLGraphicsException("SDL_Renderer no pudo ser inicializado.");
        }

    //Inicializar color de renderer
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	}

void SDLGraphics::close() {
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );

    // Cerrar subsistemas de SDL
    TTF_Quit();
    SDL_Quit();
	}

// Cargar fuente
void SDLGraphics::loadFont( std::string src, int size ) {
    if ( !( font = TTF_OpenFont( src.c_str(), size ) ) ) {
        throw SDLGraphicsException("Fallo al cargar fuente.");
        }


    }

// Getters
SDL_Window*& SDLGraphics::getWindowPtr() {
	return window;
	}

SDL_Renderer*& SDLGraphics::getRendererPtr() {
	return renderer;
	}

TTF_Font*& SDLGraphics::getFontPtr() {
    return font;
    }

void SDLGraphics::clearScreen( const Uint8 color[] ) {
    // Seleccionar color de fondo o "defecto"
    SDL_SetRenderDrawColor( renderer, color[0], color[1], color[2], color[3] );
    // Limpiar pantalla
    SDL_RenderClear( renderer );
    }

void SDLGraphics::render() {
    // Renderizar a pantalla
    SDL_RenderPresent( renderer );
    }