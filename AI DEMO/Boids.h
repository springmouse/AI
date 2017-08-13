#pragma once
#include "Object.h"

class BoidsBlackBoard; /*forwards declaration*/

/*
* Class:
* ------
*
* this is the boid class that shows off flocking
*
* Author: Callum Dunstone
*/
class Boids :
    public Object
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* this constructor takes in a refrence to its black board
	*
	*/
    Boids(BoidsBlackBoard * blackBoard);

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
    ~Boids();

	/*
	* operator==(Boids * other)
	* -------------------------
	*
	* checks if two Boids are the same by checking there position in world space
	*
	*/
    bool operator== (Boids & other);

	/*
	* operator!=(ShareBoidPtr * other)
	* --------------------------------
	*
	* checks if two Boids are not the same by checking there position in world space
	*
	*/
    bool operator!= (ShareBoidPtr & other);

	/*
	* Function: Update
	* ----------------
	*
	* update loop for the boid
	*
	* Parameters: float deltaTime so we have the deltaTime
	*
	* returns: returns nothing as it is a void function
	*/
    void Update(float deltaTime);

	/*
	* Function: Draw
	* --------------
	*
	* this draws out the boid to the screen using its world pos
	*
	* Parameters: aie::Renderer2D * renderer so that we can render things out
	*
	* returns: returns nothing as it is a void function
	*/
	void Draw(aie::Renderer2D * rendere);

	/*
	* Function: CalculateSeperation
	* -----------------------------
	*
	* this calculates out the seperation force to be applied to the boid
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void CalculateSeperation();

	/*
	* Function: CalculateAlignment
	* ----------------------------
	*
	* this calculates out the Alignment force to be applied to the boid
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void CalculateAlignment();

	/*
	* Function: CalculateCohesion
	* ---------------------------
	*
	* this calculates out the Cohesion force to be applied to the boid
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void CalculateCohesion();

	/*
	* Function: CalculateSeek
	* -----------------------
	*
	* this calculates out the seek force to be applied to the boid
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void CalculateSeek();

	/*
	* Function: CalculateWonder
	* -------------------------
	*
	* this calculates out the Wander force to be applied to the boid
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void CalculateWonder();

	/*
	* Function: GetVelocity
	* ---------------------
	*
	* this returns the boids velocity
	*
	* Parameters: none
	*
	* returns: returns m_velocity to be used for alignmeant
	*/
    Vector2 GetVelocity();

private:

    Vector2 m_speration;				/*the seperation force to be applied*/
    Vector2 m_alignment;				/*the alignmeant force to be applied*/
    Vector2 m_cohesion;					/*the cohesion force to be applied*/

    Vector2 m_velocity;					/*the boids current velocity*/
    float m_maxVelocity;				/*how fast the boid can go*/
    float m_minVolocity;				/*how slow the boid can go*/

    Vector2 m_acceleration;				/*the acceleration we will apply to m_velocity*/

    BoidsBlackBoard * m_blackBoard;		/*the units black board*/

    float m_septerationRadius;			/*the radius to do seperation checks int*/
    float m_alignmentRadius;			/*the radius to do alignmeant checks int*/
    float m_cohesionRadius;				/*the radius to do cohesion checks int*/

    float m_seperationWeight;			/*the weight of how important seperation is*/
    float m_alignmentWeight;			/*the weight of how important alignmeant is*/
    float m_cohesionWeight;				/*the weight of how important cohesion is*/

    float m_seekWeight;					/*the weight of how important seek is*/
    float m_wonderWeight;				/*the weight of how important wander is*/
};

