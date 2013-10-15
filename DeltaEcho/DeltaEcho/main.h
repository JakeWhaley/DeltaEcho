#ifndef MAIN_H
#define MAIN_H
#include "GraphicsWrappers.h"
#include "DatabaseWrappers.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <stdio.h>
#include <sqlite3.h>

int everythingThread(void *data);	//Has access to every function, at the cost of speed
int loggingThread(void *data);		//Handles massive amounts of text
int controlsThread(void *data);		//Handles input from mice, controlers, keyboards
int netThread(void *data);			//Handles input from threads and networking
int audioThread(void *data);		//Handles audio
int logicThread(void *data);		//Handles game logic
int cleanupThread(void *data);		//Checks latest output of logic thread for unused things
int normalizeThread(void *data);	//Applies Delta Time animations while waiting on an update from logic thread
int renderThread( void *data );		//Renders to OpenGL
int storageThread(void *data);		//Saves and Loads from SQLite and textfiles
int main( int argc, char* args[] );	//Main loop, governs threads

#endif