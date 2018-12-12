#include "ball.h"

void Ball::collideWithRacket(Paddle*& p) {
	// X = bola esté entre X y X + P.w
	// Y = bola esté entre Y y Y + P.h
	if ( myPhysics->getPosX() <= p->getX() + Paddle::PADDLE_WIDTH and 
		 myPhysics->getPosX() + RADIO >= p->getX() and
		 myPhysics->getPosY() <= p->getY() + Paddle::PADDLE_HEIGHT and
		 myPhysics->getPosY() + RADIO >= p->getY() ) {
		myPhysics->setVelocityX( (-1) * myPhysics->getVelocityX() );
		myPhysics->setVelocityY( (myPhysics->getPosY() - ( p->getY() + Paddle::PADDLE_HEIGHT/2 ) ) * 0.35 );
		}

	}

Ball::Ball() {
	myPhysics = new PhysicsComponent( SDLGraphics::SCREEN_WIDTH/2, 
									  SDLGraphics::SCREEN_HEIGHT/2, 
									  10.5, 
									  10.5, 
									  RADIO, 
									  RADIO );
	myGraphics = new GraphicsComponent();
	}

Ball::~Ball() {
	delete myPhysics;
	delete myGraphics;
	}

void Ball::setup( Paddle*& p1, Paddle*& p2 ) {
	paddle1 = p1;
	paddle2 = p2;
	myPhysics->setPosX(200);
	}

void Ball::update( int& scoreP1, int& scoreP2 ) {
	myPhysics->update();

	// Colisión con paredes
	if ( myPhysics->getPosY() < 0 or
		 myPhysics->getPosY() + RADIO > SDLGraphics::SCREEN_HEIGHT) {
		myPhysics->setVelocityY( (-1) * myPhysics->getVelocityY() );
		myPhysics->updateY();
		}

	// "Colisión" con paredes laterales
	if ( myPhysics->getPosX() < 0 ) {
		myPhysics->setPosXY(SDLGraphics::SCREEN_WIDTH / 2, SDLGraphics::SCREEN_HEIGHT / 2);
		scoreP2++;
		}
	if ( myPhysics->getPosX() + RADIO > SDLGraphics::SCREEN_WIDTH ) {
		myPhysics->setPosXY(SDLGraphics::SCREEN_WIDTH / 2, SDLGraphics::SCREEN_HEIGHT / 2);
		scoreP1++;
		}

	// Colisión con raquetas
	collideWithRacket(paddle1);
	collideWithRacket(paddle2);
	}

void Ball::render( SDL_Renderer*& renderer ) {
	myGraphics->drawRectangle( 	renderer, 
								myPhysics->getPosX(),
								myPhysics->getPosY(),
								myPhysics->getColliderWidth(),
								myPhysics->getColliderHeight(),
								(const Uint8[]) {0xFF, 0xFF, 0xFF, 0xFF}
							);
	}

// Setters
void Ball::setX( int x ) {
	myPhysics->setPosX(x);
	};

void Ball::setY( int y ) {
	myPhysics->setPosY(y);
	};

// Getters
int Ball::getX() {
	return myPhysics->getPosX();
	}

int Ball::getY() {
	return myPhysics->getPosY();
	}
