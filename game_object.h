#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include <SDL2/SDL.h>

class GameObject {
	protected:
	public:
		/*GameObject();
		~GameObject();*/

		virtual void setup() = 0;
		virtual void update() = 0;
	};

#endif //_GAME_OBJECT_H