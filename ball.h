#ifndef _BALL_H
#define _BALL_H

#include <SDL2/SDL.h>

#include "sdl_graphics.h"
#include "game_object.h"
#include "graphics_component.h"
#include "physics_component.h"

#include "paddle.h"

class Ball : public GameObject {
	private:
		enum States {
			STATE_IDDLE,
			STATE_MOVING
			};

		// Componentes
		PhysicsComponent* myPhysics;
		GraphicsComponent* myGraphics;

		// Paddles
		Paddle* paddle1;
		Paddle* paddle2;

		void collideWithRacket(Paddle*&);

	public:
		static const int RADIO = 20;

		Ball();
		~Ball();

		void setup() { /*setup(nullptr, nullptr);*/ }
		void setup( Paddle*&, Paddle*& );
		void update() { }
		void update( int&, int& );
		void render( SDL_Renderer*& );

		// Setters
		void setX( int );
		void setY( int );

		// Getters
		int getX();
		int getY();
	};

#endif //_BALL_H