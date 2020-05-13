#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include <vector>

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
public:
	Actor(int imageID,int startX, int startY) : m_SW(nullptr), m_alive(true) , GraphObject(imageID, startX, startY) {}
	bool getStatus() const { return m_alive;}
	void setStatus(bool state) { m_alive = state; }
private:
	StudentWorld* m_SW;
	bool m_alive;
};
class RegularProtester : public Actor {

};
class Iceman : public Actor {
public:

	//constructor?
	Iceman() : m_nugget(nullptr), Actor(IID_PLAYER, 30,60) {	//Starts out with zero gold nuggets
		//constructor stuff
		//starts at x=30, y=60
		//Should start facing rightward
		//It has an image depth of 0 – meaning its graphic image should always be in the foreground(above other images)
		//It has a size of 1.0
		m_sonar = new SonarKit;	//Is given 1 sonar charge
		m_hitPoints = 10;	//Is given 10 hit points
		for (auto it = m_squirt.begin(); it != m_squirt.end(); it++) {
			*it = new Squirt;	//Is given 5 units of water to squirt with his squirt gun(he may pick up additional Water)
		}
		setVisible(true); //make Iceman visible
	}

	void doSomething();
private: 

	int m_hitPoints;
	std::vector<Squirt*> m_squirt;
	SonarKit* m_sonar;
	GoldNugget* m_nugget;
};
class HardcoreProtester : public RegularProtester {

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

