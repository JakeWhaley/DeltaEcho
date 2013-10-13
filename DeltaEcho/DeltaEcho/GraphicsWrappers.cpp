#include "GraphicsWrappers.h"

GLuint loadTexture(char* file)
{
	GLuint texture;
	SDL_Surface* surface = IMG_Load(file);
    if (surface==NULL)  
	{
        printf("Texture Load Error: \"%s\"\n",SDL_GetError()); 
		return 0;
    }

	glGenTextures(1,&texture);
	glBindTexture(GL_TEXTURE_2D,texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w,surface->h, 0, GL_RGB,GL_UNSIGNED_BYTE,surface->pixels);
	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	SDL_FreeSurface(surface);
	
	return texture;		
};
void freeTexture(GLuint texture)
{
	glDeleteTextures(1,&texture);
};
void DrawPoint(float x, float y, float z, float u, float v)
{
	glTexCoord2f(u, v);
    glVertex3f(x, y, z);              
}