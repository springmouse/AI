#pragma once
#include <list>
#include <functional>

class Entity; /*Forward declaration of entity*/

/*
* Class: PlayerUnitDecsisionTree
* ------------------------------
*
* the Villiger Decision tree used by the entities in the pathfinding 
*
* Author: Callum Dunstone
*/
class PlayerUnitDecsisionTree
{

public:
	/*
	* Function: Constructor
	* ---------------------
	*
	* the constructor wich takes in a Entity pointer
	* wich is the entity that this tree belongs to
	*
	*/
    PlayerUnitDecsisionTree(Entity * unit);
	
	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
    ~PlayerUnitDecsisionTree();

	/*
	* Class:
	* ------
	*
	* this is the node class that the tree uses to make itself up with
	*
	* Author: Callum Dunstone
	*/
    class Node
    {

    public:
		/*
		* Function: Constructor
		* ---------------------
		*
		* Default constructor
		*
		*/
        Node() {};

		/*
		* Function: DeConstructer
		* ------------------------
		*
		* Default deConstructor.
		*
		*/
        ~Node() {};

		/*
		* Function:
		* ---------
		*
		* this is basically a function pointer, wich each node that is created
		* it will point to a diffrent true false function to run when asked
		*
		* Parameters: none
		*
		* returns: returns true false depending on how it was evaluated
		*/
        std::function<bool()> run;

        Node * yes;				/*what node it shoul run if run() == true, if nullptr then we exit the tree*/
        Node * no;				/*what node it shoul run if run() == false, if nullptr then we exit the tree*/

        std::string comment;	/*holds a comment on what the node is trying to do*/
    };

	/*
	* Function:
	* ---------
	*
	* runs through the decision tree and evaluates what to do
	*
	* Parameters: non
	*
	* returns: returns nothing as it is a void function
	*/
    void Update();

	/*
	* Function:
	* ---------
	*
	* creates all the nodes in the tree and assigns them there run functions and
	* there yes, no Node * as well as there comment
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void CreatNodes();

    std::list<Node *> nodes;	/*List of all the nodes in the tree*/
    
    Node * start;				/*the node that is the start of the tree*/

	Entity * myUnit;			/*the entity that owns this tree*/
};