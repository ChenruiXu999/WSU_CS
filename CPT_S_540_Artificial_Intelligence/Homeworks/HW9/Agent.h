// Agent.h
//
// Fall 2021 HW5 solution.
//
// Written by Larry Holder.

#ifndef AGENT_H
#define AGENT_H

#include "Action.h"
#include "Percept.h"
#include "WorldState.h"
#include "Location.h"
#include "Orientation.h"
#include "Search.h"
#include <list>

class MySearchEngine: public SearchEngine {
	virtual int HeuristicFunction (SearchState* state, SearchState* goalState);
};

class Agent
{
public:
	Agent ();
	~Agent ();
	void Initialize ();
	Action Process (Percept& percept);
	void GameOver (int score);

	void UpdateState(Action lastAction, Percept& percept, bool gameOver=false);
	Location SafeUnvisitedLocation();
	bool MemberLocation(Location& location, list<Location>& locationList);
	void UpdateSafeLocations(Location& location);
	void RemoveOutsideLocations();
	void AdjacentLocations(Location& location, list<Location>& adjacentLocations);
    void FindWumpusLocation(); // HW9 Added
    void UpdateStenchLocation(Location& location); // HW9 Added
    void UpdateWumpusLocation(Location& location); // HW9 Added
    void CheckWumpus(Location& location); // For HW9 Added
    void MoveToWumpus(); // HW9 Added
    void KillWumpus(list<Action> actions); // HW9, Added
    
	WorldState worldState;
    list<Location> stenchLocations; // HW 9 added
    Location wumpusLocation; // HW 9 added
	bool worldSizeKnown;
	list<Location> visitedLocations;
	list<Location> safeLocations; // For HW5, means not known to be unsafe
	list<Location> unsafeLocations;
	list<Action> actionList;
	MySearchEngine searchEngine;
	Action lastAction;
};

#endif // AGENT_H
