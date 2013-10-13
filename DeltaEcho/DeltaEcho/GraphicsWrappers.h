#ifndef GRAPHICSWRAPPERS_H
#define GRAPHICSWRAPPERS_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <stdio.h>

GLuint	loadTexture(char*);
void	freeTexture(GLuint);
void	DrawPoint(float x, float y, float z, float u, float v);

#endif