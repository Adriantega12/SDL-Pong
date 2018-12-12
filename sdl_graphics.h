#ifndef _SDL_GRAPHICS_H
#define _SDL_GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <exception>

class SDLGraphicsException : public std::exception {
    private:
        std::string msg;

    public:
        explicit SDLGraphicsException (const char* message) : msg(message) {}

        explicit SDLGraphicsException (const std::string& message) : msg(message) {}

        virtual ~SDLGraphicsException() throw() {}

        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

class SDLGraphics {
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
        TTF_Font* font;

	public:
		// Constants
        static const int SCREEN_WIDTH = 640;
        static const int SCREEN_HEIGHT = 480;

        // Constructors
        SDLGraphics();
        ~SDLGraphics();

        // System enter and exit
        void init();
		void close();

        // Cargar fuente
        void loadFont( std::string, int );

		// Getters
		SDL_Window*& getWindowPtr();
		SDL_Renderer*& getRendererPtr();
        TTF_Font*& getFontPtr();

        // Process
        void clearScreen( const Uint8[] );
        void render();
	};

#endif //_SDL_GRAPHICS_H