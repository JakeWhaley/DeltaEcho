Delta Echo

Table of Contents:
#About
#Goals
#Setup
#Contact
#Use
#Structure
#Suggested Structure
#Storage
#Audio
#Graphics
#Logic
#Netcode
#Logging

#About
Delta Echo is a multithreaded game engine built with C++, 
OpenGL, and SQLite. The first game to use this engine will be 
SD-6, a cooperative objective based FPS featuring proceddurally
generated levels and customizable characters. The spirit of the 
engine can be boiled down to a few goals.

#Goals
Having scalability in processing power. Should run decently on 
ancient computers, but beautifully on state of the art machines.

Separation of game logic and machine interacting code. Logic 
patches should be able to roll out regardless of the platform.

Modability to a ridiculous degree, without having to restart
the game to make use of novel code.

Threads only care about processing their queue, and only 
interact when their queue commands it.


#Setup
The master thread first looks for a master SQLite database, and
then processes according to a table known as master table. The
database can be given at command line, or it can be set to the
hardwired location of master.db

#Structure
The master thread manages lesser threads through a queue of 
commands. Threads sign off when they are done with a particular 
queue. There are several different types of lesser threads, 
which each have their own set of processing parameters.

#Suggested Structure
The suggested configuration for a game engine is 1 graphics 
thread, an on standby thread for loading, a formal game logic 
thread, a normalization game logic thread, a netcode thread, a
logging thread, and a storage thread for saving/loading.

#Storage

#Audio

#Graphics

#Logic

#Netcode

#Logging