#include <iostream>
#include <list>
#include "Agent.h"
#include <algorithm>
#include "Location.h"
#include "math.h"
using namespace std;
int MySearchEngine::HeuristicFunction(SearchState* state, SearchState* goalState) {
	return (abs(state->location.X-goalState->location.X)+abs(state->location.Y-goalState->location.Y)); }
Agent::Agent ()
{	lastAction = CLIMB;
    worldState.agentLocation = Location(1,1);
	worldState.agentOrientation = RIGHT;
	worldState.agentHasGold = false;
    worldState.worldSize = 4;
    worldState.wumpusLocation = Location(0,0);
	worldState.goldLocation = Location(0,0);
	worldSizeKnown = false;}
Agent::~Agent (){}
void Agent::Initialize (){
	worldState.agentLocation = Location(1,1);
	worldState.agentOrientation = RIGHT;
	worldState.agentAlive = true;
	worldState.wumpusAlive = true;
	worldState.agentHasGold = false;
	worldState.agentHasArrow = true;
	lastAction = CLIMB;
	actionList.clear();
	for (int x = 1; x <= 4; x++) {
		for (int y = 1; y <= 4; y++) {
			searchEngine.AddSafeLocation(x,y);
		}
	}}

Action Agent::Process (Percept& percept)
{
	list<Action> actionList2;
	if (actionList.empty()) {

	}

	Action action = actionList.front();
	actionList.pop_front();
	return action;}
void Agent::GameOver (int score){}

goldlocation=Location(0,0)//初始gold location，需要获取 gold location

KnowGoldLocation=false;

if (KnowGoldLocation==true){
	SearchEngine FindPath(state,ori,goldlocation,DOWN);
}


void UpdateGoldLocation(int x,int y){
	if (x!=0 && y!=0){
		goldlocation=Location(x,y);
	}
}

visited location
safelocation







Agent::Agent(){
	bool with_arrow=true;
	bool with_gold=false;
	location=Location(1,1);
	face_to=RIGHT;}
Agent::~Agent (){}

void Agent::Initialize(){
	with_arrow=true;
	with_gold=false;
	location=Location(1,1);
	face_to=RIGHT;
}

Orientation Agent::Change_face_to(Action action,Orientation face_to){
	if(action==TURNLEFT){
		if(face_to==RIGHT){face_to=UP;}
		else if(face_to==LEFT){face_to=DOWN;}
		else if(face_to==UP){face_to=LEFT;}
		else{face_to=RIGHT;}
	}
	else if(action==TURNRIGHT){
		if(face_to==RIGHT){face_to=DOWN;}
		else if(face_to==LEFT){face_to=UP;}
		else if(face_to==UP){face_to=RIGHT;}
		else{face_to=LEFT;}
	}
	//#print(face_to);
	return face_to;
}

Location Agent::Move(Orientation face_to,Location location){
	if(face_to == RIGHT){
		location.X +=1; }
	else if(face_to == UP){
		location.Y +=1;}
	else if(face_to == LEFT){
		location.X -=1;}
	else if(face_to == DOWN){
		location.Y -=1;}
	//cout << location.X << endl;
	//cout << location.Y << endl;
	return location;
}
Action Agent::Process (Percept& percept){
	Action action;
	if(percept.Glitter){
		action = GRAB;
		with_gold=true;
	}
	else if (with_gold==true && location==Location(1,1)){
		action =CLIMB;
	}
	else if(percept.Stench && with_arrow){
		action = SHOOT;
		with_arrow = false;
	}
	else if(percept.Bump){
		int r = rand()%2;
		if(r==0){
			action = TURNLEFT;
		}
		else if(r==1)
		{
			action = TURNRIGHT;
		}
		Change_face_to(action,face_to);
	}
	else{
		int r = rand()%10;
		if(r==0){
			action = TURNLEFT;
		}
		else if(r==1){
			action = TURNRIGHT;
			}
		else{
			action = GOFORWARD;
			}
		Change_face_to(action,face_to);
		Move(face_to,location);
		

	}
	cout<<"this is 2.0"<<endl;
	return action;
}