#ifndef _GRAPHICS_COMPONENT_H
#define _GRAPHICS_COMPONENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class GraphicsComponent {
	private:
		SDL_Texture* texture;

		int mWidth;
		int mHeight;

		void freeTexture();

	public:
		// Constructors
		GraphicsComponent();
		~GraphicsComponent();

		// Graphics and stuff
		void drawRectangle( SDL_Renderer*&, int, int, int, int, const Uint8[] );
		
		// Strings
		void loadString( SDL_Renderer*&, TTF_Font*&, std::string, SDL_Color& );
		void drawString( SDL_Renderer*&, int, int );

		// Alpha
		void setBlendMode( SDL_BlendMode blending );
		void setAlpha( Uint8 );

		// Texture
		SDL_Texture*& getTexture();

		// Getters
		int getWidth();
		int getHeight();
	};

#endif //_GRAPHICS_COMPONENT_H