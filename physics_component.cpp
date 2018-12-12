#include "physics_component.h"


bool PhysicsComponent::checkCollision(SDL_Rect& a, SDL_Rect& b) {
	//The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
	}

// Constructors
/*PhysicsComponent::PhysicsComponent() : PhysicsComponent(0, 0, 0.0, 0.0, 0, 0) { }*/

PhysicsComponent::PhysicsComponent(int _x, int _y, float _velX, float _velY, int _colH, int _colW) :
	posX(_x), posY(_y), velocityX(_velX), velocityY(_velY) {
	setColliderHeight(_colH);
	setColliderWidth(_colW);
	setColliderX(_x);
	setColliderY(_y);
	}

PhysicsComponent::~PhysicsComponent() { }

// Setters
void PhysicsComponent::setPosX( int _x ) {
	posX = _x;
	setColliderX(posX);
	}

void PhysicsComponent::setPosY( int _y ) {
	posY = _y;
	setColliderY(posY);
	}

void PhysicsComponent::setPosXY( int x, int y ) {
	setPosX(x);
	setPosY(y);
	}

void PhysicsComponent::setVelocityX( float _velX ) {
	velocityX = _velX;
	}

void PhysicsComponent::setVelocityY( float _velY ) {
	velocityY = _velY;
	}

void PhysicsComponent::setCollider( SDL_Rect& r ) {
	collider = r;
	}

void PhysicsComponent::setColliderX( int _x ) {
	collider.x = _x /*- collider.w / 2*/;
	
	}

void PhysicsComponent::setColliderY( int _y ) {
	collider.y = _y /*- collider.h / 2*/;
	}

void PhysicsComponent::setColliderHeight( int _h ) {
	// colliderHeight = _h;
	collider.h = _h;
	}

void PhysicsComponent::setColliderWidth( int _w ) {
	// colliderWidth = _w;
	collider.w = _w;
	}

// Getters
int PhysicsComponent::getPosX() {
	return posX;
	}

int PhysicsComponent::getPosY() {
	return posY;
	}

float PhysicsComponent::getVelocityX() {
	return velocityX;
	}

float PhysicsComponent::getVelocityY() {
	return velocityY;
	}

SDL_Rect& PhysicsComponent::getCollider() {
	return collider;
	}

int PhysicsComponent::getColliderX() {
	return collider.x;
	}

int PhysicsComponent::getColliderY() {
	return collider.y;
	}

int PhysicsComponent::getColliderHeight() {
	// return colliderHeight;
	return collider.h;
	}

int PhysicsComponent::getColliderWidth() {
	// return colliderWidth;
	return collider.w;
	}

void PhysicsComponent::update() {
	// Actualizar en X
	updateX();
	// Actualizar en Y
	updateY();
	}

void PhysicsComponent::updateX() {
	// Mover objeto en X
	posX += velocityX;
	setColliderX( posX );
	}

void PhysicsComponent::updateY() {
	// Mover objeto en Y
	posY += velocityY;
	setColliderY( posY );
	}

/*bool PhysicsComponent::checkCollision(SDL_Rect& r) {
	checkCollision(this->collider, r);
	}*/