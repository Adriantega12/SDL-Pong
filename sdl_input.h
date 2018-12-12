#ifndef _SDL_INPUT_H
#define _SDL_INPUT_H

#include <SDL2/SDL.h>

class SDLInput {
	private:
		Uint8* currentKeyStates;

	public:
		SDLInput();
		~SDLInput();

		Uint8* keyboardInput();
	};

#endif //_SDL_INPUT_H