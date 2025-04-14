// #pragma once

// #include <vector>
// #include <ctime>
// #include <memory>
// #include "Organism.h"
// #include "Position.h"

// using namespace std;

// class World
// {
// private:
//     int worldX;
//     int worldY;
//     int turn = 0;
//     vector<Organism*> organisms;  // Changed to pointers
//     char separator = '.';

//     string getOrganismFromPosition(int x, int y) const;
//     bool isPositionOnWorld(int x, int y) const;
//     bool isPositionFree(Position position) const;

// public:
//     World(int worldX, int worldY);
//     World() : World(6, 6) {};
//     ~World();  // Need destructor for pointer cleanup

//     int getWorldX() const { return worldX; }
//     void setWorldX(int worldX) { this->worldX = worldX; }
//     int getWorldY() const { return worldY; }
//     void setWorldY(int worldY) { this->worldY = worldY; }

//     int getTurn() const { return turn; }
    
//     void addOrganism(Organism* organism); 
//     vector<Position> getVectorOfFreePositionsAround(Position position) const;
    
//     // New method needed for Grass
//     Position findEmptyAdjacentPosition(Position position) const;
    
//     void makeTurn();
//     void writeWorld(const string& fileName) const;
//     void readWorld(const string& fileName);
    
//     string toString() const;
    
//     // Helper methods
//     bool isValidPosition(const Position& pos) const {
//         return pos.getX() >= 0 && pos.getX() < worldX && 
//                pos.getY() >= 0 && pos.getY() < worldY;
//     }
// };



// #pragma once
// #include <vector>
// #include <string>
// #include "Organism.h"
// #include "Position.h"

// class World {
// public:
//     World(int x = 20, int y = 20);  // Konstruktor
//     void addOrganism(Organism* organism);
//     void makeTurn();
//     std::string toString() const;

//     void writeWorld(std::string fileName);
//     void readWorld(const std::string& fileName);

//     std::vector<Position> getVectorOfFreePositionsAround(Position position);
//     int getWorldX() const { return worldX; }
//     int getWorldY() const { return worldY; }
// 	Position findEmptyAdjacentPosition(Position position);
// 	bool isPositionFree(Position position);
// 	Organism* getOrganismAt(const Position& pos) const;


// private:
//     int worldX, worldY;
//     int turn = 0;
//     std::vector<Organism*> organisms;
// };


#pragma once

#include <vector>
#include <ctime>
#include "Organism.h"

using namespace std;

class World
{
private:
	int worldX;
	int worldY;
	int turn = 0;
	vector<Organism*> organisms;
	char separator = '.';

	string getOrganismFromPosition(int x, int y);
	bool isPositionOnWorld(int x, int y);
	

public:
	World(int worldX, int worldY);
	World() : World(6, 6) {};

	int getWorldX();
	void setWorldX(int worldX);
	int getWorldY();
	void setWorldY(int worldY);

	int getTurn();
	
	void addOrganism(Organism *organism);
	vector<Position> getVectorOfFreePositionsAround(Position position);
	void makeTurn();

	void writeWorld(string fileName);
	void readWorld(string fileName);
	// void resetWorld()
	
	std::string toString() const;

	bool isPositionFree(Position position);
	Organism* getOrganismAt(const Position& pos) const;
	Position findEmptyAdjacentPosition(Position position);
	void removeOrganismAtPosition(Position pos);
	void removeDeadOrganisms();
	
	Organism* getOrganismFromPosition(Position pos);
};
