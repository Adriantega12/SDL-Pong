#ifndef _PADDLE_H
#define _PADDLE_H

#include <SDL2/SDL.h>

#include "sdl_graphics.h"
#include "game_object.h"
#include "physics_component.h"
#include "graphics_component.h"

class Paddle : public GameObject {
	private:
		enum State {
			STATE_IDDLE,
			STATE_MOVING
			};

		// Components
		PhysicsComponent* myPhysics;
		GraphicsComponent* myGraphics;

	public:
		static const int PADDLE_HEIGHT = 100;
		static const int PADDLE_WIDTH = 10;
		static const int PADDLE_SPEED = 15;
		
		Paddle();
		~Paddle();

		// Setters
		void setX( int );
		void setY( int );
		void setVelY( int );
		void setCollider( SDL_Rect& );

		// Getters
		int getX();
		int getY();
		int getVelX();
		SDL_Rect& getCollider();

		void setup();
		void setup(int, int);
		void handleInput();
		void update();
		void render( SDL_Renderer*& );
	};

#endif //_PADDLE_H