#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <string>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
//You may add as many other public or private methods and private member variables to this class
class StudentWorld : public GameWorld
{
public:
	StudentWorld(std::string assetDir)
		: GameWorld(assetDir)
	{
	}

	virtual int init()//write but never call
	{
		return GWSTATUS_CONTINUE_GAME;
	}

	virtual int move()//write but never call
	{
		// This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
		// Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
		decLives();
		return GWSTATUS_PLAYER_DIED;

	}

	virtual void cleanUp()//write but never call
	{
	}

private:
	//create iceman pointer
	//create vector/list of pointers to actors
	//Hint: Keeping all of your Ice objects in a separate 2D array of Ice pointers will speed things up
};

#endif // STUDENTWORLD_H_
