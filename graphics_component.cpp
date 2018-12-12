#include "graphics_component.h"

void GraphicsComponent::freeTexture() {
	if ( texture != nullptr ) {
		SDL_DestroyTexture( texture );
		}
	}

// Constructors
GraphicsComponent::GraphicsComponent() : mWidth(0), mHeight(0) {
	texture = nullptr;
	}

GraphicsComponent::~GraphicsComponent() {
	freeTexture();
	}

// Graphics and stuff
void GraphicsComponent::drawRectangle( SDL_Renderer*& renderer, int x, int y, int w, int h, const Uint8 color[] ) {
	SDL_Rect rect = { x, y, w, h };
	SDL_SetRenderDrawColor( renderer, color[0], color[1], color[2], color[3] );
    SDL_RenderDrawRect( renderer, &rect );
    SDL_RenderFillRect( renderer, &rect );
	}

void GraphicsComponent::loadString( SDL_Renderer*& renderer, TTF_Font*& font, std::string str, SDL_Color& color ) {
	// Liberar espacio de textura previa
	freeTexture();

	// Renderizar (Puede ser nulo)
	SDL_Surface* textSurface = TTF_RenderText_Solid( font, str.c_str(), color );

	//Crear textura a partir de los pixeles de la SDL_Surface (Puede ser nulo)
   	texture = SDL_CreateTextureFromSurface( renderer, textSurface );
   	
   	// Obtener dimensiones de la imagen
	mWidth = textSurface->w;
	mHeight = textSurface->h;

    // Deshacerse de superficie vieja
	SDL_FreeSurface( textSurface );
	}

void GraphicsComponent::drawString( SDL_Renderer*& renderer, int x, int y ) {
	// Crear espacio de renderizado en pantalla
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	/*if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}*/

	// Renderizar a pantalla
	SDL_RenderCopyEx( renderer, texture, NULL, &renderQuad, NULL, NULL, SDL_FLIP_NONE );
	}

// Alpha
void GraphicsComponent::setBlendMode( SDL_BlendMode blending ) {
	//Set blending function
	SDL_SetTextureBlendMode( texture, blending );
	}

void GraphicsComponent::setAlpha( Uint8 alpha ) {
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( texture, alpha );
	}

// Texture
SDL_Texture*& GraphicsComponent::getTexture() {
	return texture;
	}

int GraphicsComponent::getWidth() {
	return mWidth;
	}
	
int GraphicsComponent::getHeight() {
	return mHeight;
	}