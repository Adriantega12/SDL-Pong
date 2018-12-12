#include "enemy.h"
#include <iostream>

Enemy::Enemy() { }
Enemy::~Enemy() { }

void Enemy::setup(Paddle*& p, Ball*& b) {
	myPaddle = p;
	myBall = b;
	}

void Enemy::update() {
	int distance = myPaddle->getY() - myBall->getY();	

	if ( std::abs( distance ) > 25 ) {
        myPaddle->setVelY( ( (distance < 0) - (distance >= 0) ) * Paddle::PADDLE_SPEED );
        }
        
    std::cout << "Updated";
	}
