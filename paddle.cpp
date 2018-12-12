#include "paddle.h"

Paddle::Paddle() /*: GameObject()*/ {
	if ( !( myPhysics = new PhysicsComponent() ) ) {
		// Exception
		}
	if ( !( myGraphics = new GraphicsComponent() ) ) {
		// Exception
		}
	}

Paddle::~Paddle() {
	delete myPhysics;
	delete myGraphics;
	}

// Setters
void Paddle::setX( int x ) {
	myPhysics->setPosX(x);
	}

void Paddle::setY( int y ) {
	myPhysics->setPosY(y);
	}

void Paddle::setVelY( int velY) {
	myPhysics->setVelocityY(velY);
	}

void Paddle::setCollider( SDL_Rect& r ) {
	myPhysics->setCollider(r);
	}

// Getters
int Paddle::getX() {
	return myPhysics->getPosX();
	}

int Paddle::getY() {
	return myPhysics->getPosY();
	}

int Paddle::getVelX() {
	return myPhysics->getVelocityX();
	}

SDL_Rect& Paddle::getCollider() {
	return myPhysics->getCollider();
	}

void Paddle::setup() {
	setup(0, 0);
	}

void Paddle::setup(int x, int y) {
	myPhysics->setPosXY(x, y);
	myPhysics->setColliderWidth(PADDLE_WIDTH);
	myPhysics->setColliderHeight(PADDLE_HEIGHT);
	}

void Paddle::update() {
	myPhysics->updateY();

	// Revisar colisión con extremo de la pantalla
	/*if ( myPhysics->getPosY() - PADDLE_HEIGHT / 2 < 0 or 
		myPhysics->getPosY() + PADDLE_HEIGHT / 2 > SDLGraphics::SCREEN_HEIGHT ) {
		// Si su posición se pasa, entonces se invierte la velocidad y actualiza nuevamente
		myPhysics->setVelocityY( (-1) * myPhysics->getVelocityY() );
		myPhysics->updateY();
		}*/
	if ( myPhysics->getPosY() < 0 or 
		myPhysics->getPosY() + PADDLE_HEIGHT > SDLGraphics::SCREEN_HEIGHT ) {
		// Si su posición se pasa, entonces se invierte la velocidad y actualiza nuevamente
		myPhysics->setVelocityY( (-1) * myPhysics->getVelocityY() );
		myPhysics->updateY();
		}
	}

void Paddle::render( SDL_Renderer*& renderer ) {
	/*myGraphics->drawRectangle( renderer,  
							   myPhysics->getPosX() - PADDLE_WIDTH/2,
							   myPhysics->getPosY() - PADDLE_HEIGHT/2,
							   PADDLE_WIDTH,
							   PADDLE_HEIGHT,
							   (const Uint8[]){0xFF, 0xFF, 0xFF, 0xFF}
							   );*/
	myGraphics->drawRectangle( renderer,  
							   myPhysics->getPosX(),
							   myPhysics->getPosY(),
							   PADDLE_WIDTH,
							   PADDLE_HEIGHT,
							   (const Uint8[]){0xFF, 0xFF, 0xFF, 0xFF}
							   );
	/*myGraphics->drawRectangle( renderer, 
							   myPhysics->getColliderX(),
							   myPhysics->getColliderY(),
							   PADDLE_WIDTH,
							   PADDLE_HEIGHT,
							   (const Uint8[]) {0xFF, 0x00, 0x00, 0x0A}
							 );*/
	}