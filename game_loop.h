#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED

#include <SDL2/SDL.h>
#include <exception>
#include <string>

#include "sdl_graphics.h"
#include "sdl_input.h"
#include "game_state.h"
#include "game_state_menu.h"
#include "game_state_play.h"

class GameLoopException : public std::exception {
    private:
        std::string msg;

    public:
        explicit GameLoopException (const char* message) : msg(message) {}

        explicit GameLoopException (const std::string& message) : msg(message) {}

        virtual ~GameLoopException() throw() {}

        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

class GameLoop {
    private:
        enum {
            GAME_STATE_MENU,
            GAME_STATE_PLAY
            };

        // Módulos de SDL
        SDLGraphics* sdlGraphics; 
        SDLInput* sdlInput;

        // Estado de juego
        GameState* currentGS;

        // Process
        void setup();
        void handleInput();
        void update();
        void preRender(); // Wrapper de render
        void render();

    public:
        // Constr y Destr
        GameLoop();
        ~GameLoop();

        // Loop
        void loop();
    };

#endif // GAMELOOP_H_INCLUDED
