Controls:
escape will bring you back to the main menue while in the flocking or pathinding
Right click will creat new units while in the pathfinding

Decision Make technics:
in pathfinding and deciscions the entities there use a combination of four diffren decision makeing technics.
you have a black board that holds all the out side world things that each entity needs to know about and needs acces to.
then you have a utilites AI that will looks at the unit it is on and acces the black board to calculate a value for one of five diffrent checks
being gather food, muder your friends, attack a nearby murder, just wander around or flee from an attacker.
you then have the decision tree wich will evaluate the diffrent values from utilites to come up with a course of action for the entity and it to acces the black
board for information to better help it decied the best course of action and then it will set up the entities state machine to exacute that course of action.
you then have the statemachine with has four diffrent states move, attack, murder and gather food. move will always be at the bottom but depending on how
the decision tree exacuted and decided what it can do you will have either attack on top of move if it wants to attack a murder or murder if its trying to kill its
friends or gather food if its just trying to be peacfull;

the boids in flocking also make use of a blackboard so they can figure out where everyone is and where they are going

PathFinding:
implameants an A* pathfinding with pathsmoothing using line of sight checks, the map is made with a Dynamically created navmesh that the player can add on or remove as they like
easily changeing up the map and they can effectivly calculate the edges of the map for line of sight checks, nodes also have an internall connection to all nodes touching its
edges, this is not a problem for diaginall movmeant however with path smoothing. all nodes are also stored with in a list.
note while you can make islands seperated from eachother with no connection and pathfinding will still work but the desciscion tree does not like it and will 
try and give the entites impossible tasks to commplete if for example there is food on one island and not the other or a murder on one but not the other, 
the decision tree might try and tell them to go after one off those but as there is no path they will currently frezze in this version of the build.

Sterring:
we have flocking, flocking uses the seperation, coheasion, and allignmeant by checking within a certin radius either around them or one progected infront of them
as well as a weak seek force to the center of the screen to try and reduce them clumping up at the edges of the scree, 
the entites in the path finding also technically use seek behaviours to move between nodes i guess

