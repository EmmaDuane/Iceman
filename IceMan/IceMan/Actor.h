#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

//GraphObject Class already includes:
//nonvirtual constructor
//virutal destructor
//bool	    m_visible  //setVisible(bool)  sets whether or not object is visible
//double	m_x, m_y;  //getX(),getY() position of object
//double	m_destX, m_destY; //moveTo(int x,int y)  moves object to new coordinates
//double	m_brightness  //setBrightness(double)  sets brightness of object
//double	m_size;  //getSize()  returns size of object
//Direction	m_direction;  //getDirection(), setDirection(Direction) gets and sets direction

class Actor : public GraphObject {

};
class Protester : public Actor {

};
class IceMan {

};
class HardcoreProtester : public Protester {

};
class RegularProtester : public Protester {

};
class Squirt {

};
class Barrel {

};
class Boulder {

};
class GoldNugget {

};
class SonarKit {

};
class Water {

};
class Ice {

};

#endif // ACTOR_H_

