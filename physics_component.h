#ifndef _PHYSICS_COMPONENT_H
#define _PHYSICS_COMPONENT_H

#include <SDL2/SDL.h>

class PhysicsComponent {
	private:
		int posX;
		int posY;
		float velocityX;
		float velocityY;
		// int colliderHeight;
		// int colliderWidth;
		SDL_Rect collider;

		bool checkCollision(SDL_Rect& a, SDL_Rect& b);

	public:
		// Constructors
		//PhysicsComponent();
		PhysicsComponent(int = 0, int = 0, float = 0.0, float = 0.0, int = 0, int = 0);
		~PhysicsComponent();

		// Setters
		void setPosX( int );
		void setPosY( int );
		void setPosXY( int, int );
		void setVelocityX( float );
		void setVelocityY( float );
		void setCollider( SDL_Rect& );
		void setColliderX( int );
		void setColliderY( int );
		void setColliderHeight( int );
		void setColliderWidth( int );

		// Getters
		int getPosX();
		int getPosY();
		float getVelocityX();
		float getVelocityY();
		SDL_Rect& getCollider();
		int getColliderX();
		int getColliderY();
		int getColliderHeight();
		int getColliderWidth();

		// Process
		void update();
		void updateX();
		void updateY();

		//bool checkCollision(SDL_Rect&);
	};

#endif //_PHYSICS_COMPONENT_H