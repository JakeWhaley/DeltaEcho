##Delta Echo

#About
Delta Echo is a multithreaded game engine built with C++, 
OpenGL, and SQLite. It features a model structure savable into
an SQL database, and can use a queue of commands to control
it's structure from database, net commands, or even in game
scripting. A map maker, trigger editor, model converter, and
code translator are planned, but not in development yet.

#Goals
Having scalability in processing power. Should run decently on 
ancient computers, but beautifully on state of the art machines.

Separation of game logic and machine interacting code. Logic 
patches should be able to roll out regardless of the platform.

Modability to a ridiculous degree, without having to restart
the game to make use of novel code.

Threads only care about processing their queue, and only 
interact when their queue commands it.

#General IDE Setup
This project makes use of SDL2, SDL2-image, and SQLite3 
libraries.

#Setup
The master thread first looks for a master SQLite database 
(master.db), and then processes according to a table known as 
master table (master). The database can be given at command 
line otherwise it will be set to the hardwired location of 
master.db

#Structure
The master thread manages lesser threads through a queue of 
commands. Threads sign off when they are done with a particular 
queue. There are several different types of lesser threads, 
which each have their own set of processing parameters.

#Suggested Structure
The suggested configuration for a game engine is 1 graphics 
thread, an on standby thread for loading, a control input 
thread, a formal game logic thread, a normalization game logic
thread, a cleanup thread, a netcode thread, a logging thread, 
and a storage thread for saving/loading.

#Storage

#Audio

#Graphics

#Logic

#Netcode

#Logging