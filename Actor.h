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
	Actor(int hitPoints, int annoy, int imageID,int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0)
		:  m_SW(nullptr), m_alive(true) , GraphObject(imageID, startX, startY, dir, size, depth)
	{
		m_annoy = annoy;
	}
	bool getStatus() const { return m_alive;} //returns true if alive, false if dead
	void setStatus(bool state) { m_alive = state; } //sets objects to dead or alive
private:
	StudentWorld* m_SW;
	bool m_alive;  //dead/alive status
	int m_annoy; //annoyance points	
	int m_hitPoints;
};
class RegularProtester : public Actor {
public: 
	RegularProtester(int x, int y) : Actor(5, 100, IID_PROTESTER, x,y, left) {//?? what are x and y?
		setVisible(true);
	} 
};
class Iceman : public Actor {
public:

	//constructor?
	Iceman() : m_squirt(nullptr), m_nugget(nullptr), Actor(10,100,IID_PLAYER, 30,60) {	//Starts out with zero gold nuggets
		//constructor stuff
		//starts at x=30, y=60
		//Should start facing rightward
		//It has an image depth of 0 – meaning its graphic image should always be in the foreground(above other images)
		//It has a size of 1.0
		m_sonar = new SonarKit;	//Is given 1 sonar charge
		for (auto it = m_water.begin(); it != m_water.end(); it++) {
			*it = new Water;	//Is given 5 units of water to squirt with his squirt gun(he may pick up additional Water)
		}
		setVisible(true); //make Iceman visible
	}
	void doSomething();

private: 
	std::vector<Water*> m_water;
	Squirt* m_squirt;
	SonarKit* m_sonar;
	GoldNugget* m_nugget;
};

class HardcoreProtester : public Actor{
public:
	HardcoreProtester(int x, int y) : Actor(20, 100, IID_HARD_CORE_PROTESTER, x, y, left) {//?? what are x and y?
		setVisible(true);
	}

};

class IceObject : public GraphObject {
public: 
	IceObject(int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0, int ticks = 0)
		: m_SW(nullptr), m_alive(true), GraphObject(imageID, startX, startY, dir, size, depth) { }
	int get_ticks() const { return num_ticks; } //returns number of ticks the object has left
private:
	StudentWorld* m_SW;
	bool m_alive;  //dead/alive status
	int num_ticks;
};

class Squirt : public IceObject{
public:
	Squirt(int x, int y, Direction dir) : IceObject(IID_WATER_SPURT, x,y,dir,1.0,1) {
		m_distance = 4;
		setVisible(true);
	}
private:
	int m_distance;
};
class Barrel : public IceObject{
public:
	Barrel(int x, int y) : IceObject(IID_BARREL, x, y, right, 1.0, 2) {
		setVisible(false);
	}
};

class Boulder : public IceObject {
	Boulder(int x, int y) : IceObject(IID_BOULDER, x, y, down, 1.0, 1) {
		setVisible(true);
	}
};

class GoldNugget : public IceObject {
public:
	GoldNugget(int ticks, int x, int y, bool visible,bool pickup, bool permanent) : IceObject(IID_GOLD, x, y, right, 1.0, 2, ticks) {
		setVisible(visible);
		m_pickup = pickup;
		m_permanent = permanent;
	}
	bool isPermanent() const{ return m_permanent; }
	bool pickupStatus() const{ return m_pickup; }
private:
	bool m_pickup; //true if Iceman can pick up nugget, flase if Protester can pick up nugget
	bool m_permanent; //true if permanent, false if temporary
};

class SonarKit : public IceObject {
public:
	SonarKit(int x, int y) : IceObject(IID_SONAR, x, y, right, 1.0, 2) {
		setVisible(true);
		//num_ticks = max(100, 300 – 10 * current_level_number)??
	}
};

class Water : public IceObject {
public:
	Water(int x, int y) : IceObject(IID_WATER_POOL, x, y, right, 1.0, 2) {
		setVisible(true);
		//num_ticks = max(100, 300 – 10*current_level_number)??
	}
};

class Ice : public IceObject {
	Ice(int x, int y) : IceObject(IID_ICE, x, y, right, 0.25, 3) { 
		setVisible(true);
	}
};

#endif // ACTOR_H_

