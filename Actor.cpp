#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp
void Iceman::doSomething() {


	//a.The Iceman must check to see if it is currently alive. If not, then its doSomething() method must return immediately
	//b.If the Iceman’s 4x4 image currently overlaps any Ice objects within the oil field, 
		//then it will call upon the StudentWorld object to :
			//1.Remove / destroy the Ice objects from the 4x4 area occupied by the Iceman(from x, y to x + 3, y + 3 inclusive)
			//2.Make a digging sound by playing the SOUND_DIG sound(see the
			//StudentWorld section of this document for details on how to play a sound)
	//c. doSomething() method must check to see if the human player pressed a key
			//1. Escape key: the Iceman object should set itself to 
				//completely annoyed(aka dead).The code in your StudentWorld class should detect that the
				//Iceman has died and address this appropriately(e.g., replay the level from
				//scratch, or end the game if the player has run out of lives)
			//2. spacebar key: 
				//Iceman will fire a Squirt into the oil field
				//check for sufficient water in their squirt gun 
				//Iceman will then reduce their water count by 1.
				//create and add a new Squirt object into the oil field at a location that is
					//four squares immediately in front of the Iceman, facing the same direction as Iceman.
				//play SOUND_PLAYER_SQUIRT.
				//If the initial location where the Squirt starts (i.e., 4 squares in front of the 
				//Iceman) is occupied by one or more Ice objects or is within a radius of 3.0 of a
				//Boulder object, then the Iceman must still make a squirting noiseand will
				//waste 1 unit of water, but the Iceman must not add any Squirt object into the
				//oil fieldand thus no damage can be done to any Protesters
											//HINT: One way to implement this is to have your Iceman create a new Squirt
											//object in the proper locationand facing the proper direction, and then give it
											//to your StudentWorld to manage(i.e., to animate) along with your other
											//game objects.
			//3.arrow keys:
				//If the player wants their Iceman to turn to face a different direction then it is currently facing
					// then adjust Iceman’s direction but the Iceman but don't move 
				//Else if Iceman is already facing the particular direction 
					//AND the Iceman is allowed to move in that direction(e.g., there is no Boulder in the way,
					//and the position doesn’t take the Iceman outside of the oil field), 
					//then use GraphObject’s moveTo() method to adjust Iceman’s location by one square in indicated direction.
				//Valid coordinates for the Iceman are [0 <= x <= 60]  [0 <= y <= 60]
					//Moreover, the Iceman cannot occupy a square that is less than
					//or equal to a radius of 3 away from the center of any Boulder
			//4. Z or z:
				//if Iceman has one or more sonar charges remaining in his inventory, then this will cause the Iceman
					//to use his sonar charge to illuminate the contents of the oil field within a radius of 12 of his location
				//The count of sonar charges held by the Iceman must be decremented by 1.
				//All hidden game objects(e.g., Gold Nuggets or Barrels of oil) within a radius of 12 (this includes 11.99 squares away)
				//must be made visible via setVisible()
			//5.tab:
				//if they have one or more units of gold in their inventory, 
					//add a Gold Nugget object into the oil field at their current x, y locationa  
					//reduce their gold count by 1 unit.
					//The dropped Gold Nugget must have a  lifetime of 100 game ticks, and is only pickup-able by Protesters
					//set nugget to visible via setVisible()
	//d.if Iceman is Annoyed (gets shouted at by protestor)
		//hit-points should be decremented by the appropriate amount(e.g., 2 points)
		//HINT: All objects that can be annoyed should have some type of method that can be called to annoy them.
		//If the Iceman’s hit-points reach zero or below due to being annoyed
			//set Iceman object’s state to dead, and then play sound effect : SOUND_PLAYER_GIVE_UP
		//Note: The StudentWorld class should check the Iceman’s status during each tickand if he transitions to a dead state, it should return
		//the appropriate value indicating that the player lost a life.
	//e.getting input from user
		//use getKey() to get input from the user 
		//Since your Iceman class will need to access the getKey() method in the GameWorld class (which is 
			//the base class for your StudentWorld class), your Iceman class (or more correctly, one of its base classes)
			//will need to obtain a pointer to the StudentWorld class.
		// If the user hit a key, the function returns true and the int variable passed to it is set to the code for the key.
		//Otherwise, the function immediately returns false, meaning that no key was hit.
		//possible implementation: 
	//void Iceman::doSomething()
	//{
	//	...
	//		int ch;
	//	if (getWorld()->getKey(ch) == true)
	//	{
	//		// user hit a key this tick! 
	//		switch (ch)
	//		{
	//		case KEY_PRESS_LEFT:
	//			... move player to the left ...;
	//			break;
	//		case KEY_PRESS_RIGHT:
	//			... move player to the right ...;
	//			break;
	//		case KEY_PRESS_SPACE:
	//			... add a Squirt in front of the player...;
	//			break;
	//			// etc…
	//		}
	//	}
	//	...
	//}
}