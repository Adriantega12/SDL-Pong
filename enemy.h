#ifndef _ENEMY_H
#define _ENEMY_H

#include "paddle.h"
#include "ball.h"

class Enemy {
	private:
		Paddle* myPaddle;
		Ball* myBall;

	public:
		Enemy();
		~Enemy();

		void setup(Paddle*&, Ball*&);
		void update();
	};

#endif //_ENEMY_H