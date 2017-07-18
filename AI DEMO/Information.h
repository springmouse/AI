#pragma once


#define INFOMATION Information::GetInstanceOfInfo()

/*
* Class: Information
* ------------------
*
* this is used to transfer information between classes
*
* Author: Callum Dunstone
*/
class Information
{
public:

	/*
	* Function: GetInstanceOfInfo
	* ------------------------------
	*
	* this function returns a static instance of Information so this to make this class a singleton
	*
	* Parameters: it takes no parameters
	*
	* returns: a static pointer to Information
	*/
    static Information * GetInstanceOfInfo();

	/*
	* Function: pushInfo
	* ------------------
	*
	* this function takes in the push info for what we want to push onto m_stateStack in GameStateManager
	*
	* Parameters: int ID is the GameState ID we want to push onto m_stateStack in GameStateManager
	*
	* returns: nothing is a void function
	*/
    void pushInfo(int ID) { pushID = ID; push = true; };

    bool quit = false; /*flag for if the programe should end or not*/
    bool push = false; /*flag if we should push a state on the m_stateStack in GameStateManager*/
    bool pop = false; /*flag if we should pop a state on the m_stateStack in GameStateManager*/

    int pushID = 0; /*ID for what game state we want to push on to the m_stateStack in GameStateManager*/

private:

	/*
	* Class: Unit
	* -----------
	*
	* this is the base Unit that all the rest are derived from
	*
	* Author: Callum Dunstone
	*/
	Information() {};

	/*
	* Function: DeConstructor
	* ---------------------
	*
	* this is the Default Deconstructor of the class
	*
	*/
	~Information() {};
};

