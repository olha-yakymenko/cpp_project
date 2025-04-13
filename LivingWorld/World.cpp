// #include "World.h"
// #include <fstream>
// #include <algorithm>

// string World::getOrganismFromPosition(int x, int y)
// {	
// 	for (Organism org : organisms)
// 		if (org.getPosition().getX() == x && org.getPosition().getY() == y)
// 			return org.getSpecies();
// 	return "";
// }

// bool World::isPositionOnWorld(int x, int y)
// {
// 	return (x >= 0 && y >= 0 && x < getWorldX() && y < getWorldY());
// }

// bool World::isPositionFree(Position position) {
// 	return this->getOrganismFromPosition(position.getX(), position.getY()).empty();
// }

// vector<Position> World::getVectorOfFreePositionsAround(Position position)
// {	
// 	int pos_x = position.getX(), pos_y = position.getY();
// 	vector<Position> result;
// 	for(int x = -1; x < 2; ++x)
// 		for (int y = -1; y < 2; ++y)
// 			if ((x != 0 || y != 0) && 
// 				isPositionOnWorld(pos_x + x, pos_y + y)) {
// 				result.push_back(Position(pos_x + x, pos_y + y));
// 			}
// 	auto iter = remove_if(result.begin(), result.end(),
// 		[this](Position pos) {return !isPositionFree(pos); });
// 	result.erase(iter, result.end());

// 	return result;
// }

// World::World(int worldX, int worldY)
// {
// 	setWorldX(worldX);
// 	setWorldY(worldY);
// }

// int World::getWorldX()
// {
// 	return this->worldX;
// }

// void World::setWorldX(int worldX)
// {
// 	this->worldX = worldX;
// }

// int World::getWorldY()
// {
// 	return this->worldY;
// }

// void World::setWorldY(int worldY)
// {
// 	this->worldY = worldY;
// }

// int World::getTurn()
// {
// 	return this->turn;
// }

// void World::addOrganism(Organism* organism)
// {
// 	this->organisms.push_back(*organism);
// }

// void World::makeTurn()
// {
// 	vector<Position> newPositions;
// 	int numberOfNewPositions;
// 	int randomIndex;

// 	srand(time(0));
// 	for (auto& org : organisms) {
// 		newPositions = getVectorOfFreePositionsAround(org.getPosition());
// 		numberOfNewPositions = newPositions.size();
// 		if (numberOfNewPositions > 0) {
// 			randomIndex = rand() % numberOfNewPositions;
// 			org.setPosition(newPositions[randomIndex]);
// 		}
// 	}
// 	turn++;
// }

// void World::writeWorld(string fileName)
// {
// 	fstream my_file;
// 	my_file.open(fileName, ios::out | ios::binary);
// 	if (my_file.is_open()) {
// 		my_file.write((char*)&this->worldX, sizeof(int));
// 		my_file.write((char*)&this->worldY, sizeof(int));
// 		my_file.write((char*)&this->turn, sizeof(int));
// 		int orgs_size = this->organisms.size();
// 		my_file.write((char*)&orgs_size, sizeof(int));
// 		for (int i = 0; i < orgs_size; i++) {
// 			int data;
// 			data = this->organisms[i].getPower();
// 			my_file.write((char*)&data, sizeof(int));
// 			data = this->organisms[i].getPosition().getX();
// 			my_file.write((char*)&data, sizeof(int));
// 			data = this->organisms[i].getPosition().getY();
// 			my_file.write((char*)&data, sizeof(int));
// 			string s_data = this->organisms[i].getSpecies();
// 			int s_size = s_data.size();
// 			my_file.write((char*)&s_size, sizeof(int));
// 			my_file.write(s_data.data(), s_data.size());
// 		}
// 		my_file.close();
// 	}
// }

// void World::readWorld(string fileName)
// {
// 	fstream my_file;
// 	my_file.open(fileName, ios::in | ios::binary);
// 	if (my_file.is_open()) {
// 		int result;
// 		my_file.read((char*)&result, sizeof(int));
// 		this->worldX = (int)result;
// 		my_file.read((char*)&result, sizeof(int));
// 		this->worldY = (int)result;
// 		my_file.read((char*)&result, sizeof(int));
// 		this->turn = (int)result;
// 		my_file.read((char*)&result, sizeof(int));
// 		int orgs_size = (int)result;
// 		vector<Organism> new_organisms;
// 		for (int i = 0; i < orgs_size; i++) {
// 			int power;
// 			my_file.read((char*)&result, sizeof(int));
// 			power = (int)result;

// 			int pos_x;
// 			my_file.read((char*)&result, sizeof(int));
// 			pos_x = (int)result;
// 			int pos_y;
// 			my_file.read((char*)&result, sizeof(int));
// 			pos_y = (int)result;
// 			Position pos{ pos_x, pos_y };
			
// 			int s_size;
// 			my_file.read((char*)&result, sizeof(int));
// 			s_size = (int)result;

// 			string species;
// 			species.resize(s_size);
// 			my_file.read((char*)&species[0], s_size);
			
// 			Organism org(power, pos);
// 			org.setSpecies(species);
// 			new_organisms.push_back(org);
// 		}
// 		this->organisms = new_organisms;
// 		my_file.close();
// 	}
// }

// string World::toString()
// {
// 	string result = "\nturn: " + to_string(getTurn()) + "\n";
// 	string spec;

// 	for (int wY = 0; wY < getWorldY(); ++wY) {
// 		for (int wX = 0; wX < getWorldX(); ++wX) {
// 			spec = getOrganismFromPosition(wX, wY);
// 			if (spec != "")
// 				result += spec;
// 			else
// 				result += separator;
// 		};
// 		result += "\n";
// 	}
// 	return result;
// }




// #include "World.h"
// #include <fstream>
// #include <algorithm>

// string World::getOrganismFromPosition(int x, int y)
// {
//     for (Organism org : organisms)
//         if (org.getPosition().getX() == x && org.getPosition().getY() == y)
//             return org.getSpecies();
//     return "";
// }

// bool World::isPositionOnWorld(int x, int y)
// {
//     return (x >= 0 && y >= 0 && x < getWorldX() && y < getWorldY());
// }

// bool World::isPositionFree(Position position)
// {
//     return this->getOrganismFromPosition(position.getX(), position.getY()).empty();
// }

// vector<Position> World::getVectorOfFreePositionsAround(Position position)
// {
//     int pos_x = position.getX(), pos_y = position.getY();
//     vector<Position> result;
//     for (int x = -1; x < 2; ++x)
//         for (int y = -1; y < 2; ++y)
//             if ((x != 0 || y != 0) && isPositionOnWorld(pos_x + x, pos_y + y))
//             {
//                 result.push_back(Position(pos_x + x, pos_y + y));
//             }

//     auto iter = remove_if(result.begin(), result.end(),
//                           [this](Position pos) { return !isPositionFree(pos); });
//     result.erase(iter, result.end());

//     return result;
// }

// World::World(int worldX, int worldY)
// {
//     setWorldX(worldX);
//     setWorldY(worldY);
// }

// int World::getWorldX()
// {
//     return this->worldX;
// }

// void World::setWorldX(int worldX)
// {
//     this->worldX = worldX;
// }

// int World::getWorldY()
// {
//     return this->worldY;
// }

// void World::setWorldY(int worldY)
// {
//     this->worldY = worldY;
// }

// int World::getTurn()
// {
//     return this->turn;
// }

// void World::addOrganism(Organism* organism)
// {
//     this->organisms.push_back(*organism);
// }

// void World::makeTurn()
// {
//     vector<Position> newPositions;
//     int numberOfNewPositions;
//     int randomIndex;

//     srand(time(0));
//     for (auto& org : organisms)
//     {
//         newPositions = getVectorOfFreePositionsAround(org.getPosition());
//         numberOfNewPositions = newPositions.size();
//         if (numberOfNewPositions > 0)
//         {
//             randomIndex = rand() % numberOfNewPositions;
//             org.setPosition(newPositions[randomIndex]);
//         }
//     }
//     turn++;
// }

// void World::writeWorld(string fileName)
// {
//     fstream my_file;
//     my_file.open(fileName, ios::out | ios::binary);
//     if (my_file.is_open())
//     {
//         my_file.write((char*)&this->worldX, sizeof(int));
//         my_file.write((char*)&this->worldY, sizeof(int));
//         my_file.write((char*)&this->turn, sizeof(int));
//         int orgs_size = this->organisms.size();
//         my_file.write((char*)&orgs_size, sizeof(int));
//         for (int i = 0; i < orgs_size; i++)
//         {
//             int data;
//             data = this->organisms[i].getPower();
//             my_file.write((char*)&data, sizeof(int));
//             data = this->organisms[i].getPosition().getX();
//             my_file.write((char*)&data, sizeof(int));
//             data = this->organisms[i].getPosition().getY();
//             my_file.write((char*)&data, sizeof(int));
//             string s_data = this->organisms[i].getSpecies();
//             int s_size = s_data.size();
//             my_file.write((char*)&s_size, sizeof(int));
//             my_file.write(s_data.data(), s_data.size());
//         }
//         my_file.close();
//     }
// }

// void World::readWorld(string fileName)
// {
//     fstream my_file;
//     my_file.open(fileName, ios::in | ios::binary);
//     if (my_file.is_open())
//     {
//         int result;
//         my_file.read((char*)&result, sizeof(int));
//         this->worldX = (int)result;
//         my_file.read((char*)&result, sizeof(int));
//         this->worldY = (int)result;
//         my_file.read((char*)&result, sizeof(int));
//         this->turn = (int)result;
//         my_file.read((char*)&result, sizeof(int));
//         int orgs_size = (int)result;
//         vector<Organism> new_organisms;
        
//         for (int i = 0; i < orgs_size; i++)
//         {
//             int power;
//             my_file.read((char*)&result, sizeof(int));
//             power = (int)result;

//             int pos_x;
//             my_file.read((char*)&result, sizeof(int));
//             pos_x = (int)result;
//             int pos_y;
//             my_file.read((char*)&result, sizeof(int));
//             pos_y = (int)result;
//             Position pos{pos_x, pos_y};  // Przekazywanie przez wartość

//             int s_size;
//             my_file.read((char*)&result, sizeof(int));
//             s_size = (int)result;

//             string species;
//             species.resize(s_size);
//             my_file.read((char*)&species[0], s_size);

//             // Wartości domyślne dla pozostałych argumentów
//             int initiative = 1;  // lub jakąś inną wartość domyślną
//             int liveLength = 10;  // wartość domyślna
//             int powerToReproduce = 5;  // wartość domyślna
//             char sign = species[0];  // np. pierwszy znak gatunku
//             World* world = nullptr;  // Załóżmy, że wczytujesz świat później lub nie masz dostępu

//             // Konstruktor Organism z wszystkimi parametrami
//             Organism org(power, pos, species, initiative, liveLength, powerToReproduce, sign, world);
//             new_organisms.push_back(org);
//         }

//         this->organisms = new_organisms;
//         my_file.close();
//     }
// }


// string World::toString()
// {
//     string result = "\nturn: " + to_string(getTurn()) + "\n";
//     string spec;

//     for (int wY = 0; wY < getWorldY(); ++wY)
//     {
//         for (int wX = 0; wX < getWorldX(); ++wX)
//         {
//             spec = getOrganismFromPosition(wX, wY);
//             if (spec != "")
//                 result += spec;
//             else
//                 result += separator;
//         }
//         result += "\n";
//     }
//     return result;
// }

// Position World::findEmptyAdjacentPosition(Position position) const {
//     const vector<Position> directions = {
//         Position(0, 1), Position(1, 0), Position(0, -1), Position(-1, 0)
//     };
    
//     for (const auto& dir : directions) {
//         Position newPos(position.getX() + dir.getX(), 
//                        position.getY() + dir.getY());
        
//         if (isValidPosition(newPos) && isPositionFree(newPos)) {
//             return newPos;
//         }
//     }
//     return Position(-1, -1);  // Invalid position if none found
// }




// #include "World.h"
// #include <fstream>
// #include <algorithm>
// #include <memory>
// #include <cstdlib>
// #include "Grass.h"

// string World::getOrganismFromPosition(int x, int y) const
// {
//     for (const auto& org : organisms)
//         if (org->getPosition().getX() == x && org->getPosition().getY() == y)
//             return org->getSpecies();
//     return "";
// }

// bool World::isPositionOnWorld(int x, int y) const
// {
//     return (x >= 0 && y >= 0 && x < worldX && y < worldY);
// }

// bool World::isPositionFree(Position position) const
// {
//     for (const auto& org : organisms) {
//         if (org->getPosition() == position) {
//             return false;
//         }
//     }
//     return true;
// }

// vector<Position> World::getVectorOfFreePositionsAround(Position position) const
// {
//     vector<Position> result;
//     int pos_x = position.getX();
//     int pos_y = position.getY();
    
//     for (int x = -1; x <= 1; ++x) {
//         for (int y = -1; y <= 1; ++y) {
//             if ((x != 0 || y != 0)) {
//                 Position newPos(pos_x + x, pos_y + y);
//                 if (isPositionOnWorld(newPos.getX(), newPos.getY()) ){
//                     result.push_back(newPos);
//                 }
//             }
//         }
//     }

//     result.erase(
//         remove_if(result.begin(), result.end(),
//                  [this](const Position& pos) { return !isPositionFree(pos); }),
//         result.end()
//     );

//     return result;
// }

// World::World(int worldX, int worldY) : worldX(worldX), worldY(worldY)
// {
// }

// World::~World()
// {
//     for (auto org : organisms) {
//         delete org;
//     }
// }

// void World::addOrganism(Organism* organism)
// {
//     if (organism && isPositionOnWorld(organism->getPosition().getX(), 
//                                     organism->getPosition().getY())) {
//         organisms.push_back(organism);
//         organism->setWorld(this);
//     }
// }

// void World::makeTurn()
// {
//     // Sort organisms by initiative
//     sort(organisms.begin(), organisms.end(),
//         [](Organism* a, Organism* b) {
//             return a->getInitiative() > b->getInitiative();
//         });

//     vector<Organism*> newOrganisms;
    
//     for (auto& org : organisms) {
//         if (org->isAlive()) {
//             org->move(0, 0);
//             org->decreaseLife();
            
//             if (org->getPowerToReproduce() <= 0) {
//                 Position newPos = findEmptyAdjacentPosition(org->getPosition());
//                 if (newPos.isValid()) {
//                     Organism* child = org->clone();
//                     child->setPosition(newPos);
//                     newOrganisms.push_back(child);
//                     org->setPowerToReproduce(org->getInitialPowerToReproduce());
//                 }
//             }
//         }
//     }

//     // Add new organisms
//     for (auto org : newOrganisms) {
//         addOrganism(org);
//     }

//     // Remove dead organisms
//     organisms.erase(
//         remove_if(organisms.begin(), organisms.end(),
//                  [](Organism* org) { return !org->isAlive(); }),
//         organisms.end()
//     );

//     turn++;
// }

// void World::writeWorld(const string& fileName) const
// {
//     ofstream my_file(fileName, ios::binary);
//     if (my_file.is_open()) {
//         my_file.write(reinterpret_cast<const char*>(&worldX), sizeof(worldX));
//         my_file.write(reinterpret_cast<const char*>(&worldY), sizeof(worldY));
//         my_file.write(reinterpret_cast<const char*>(&turn), sizeof(turn));
        
//         int orgs_size = organisms.size();
//         my_file.write(reinterpret_cast<const char*>(&orgs_size), sizeof(orgs_size));
        
//         for (const auto& org : organisms) {
//             int data = org->getPower();
//             my_file.write(reinterpret_cast<const char*>(&data), sizeof(data));
            
//             data = org->getPosition().getX();
//             my_file.write(reinterpret_cast<const char*>(&data), sizeof(data));
            
//             data = org->getPosition().getY();
//             my_file.write(reinterpret_cast<const char*>(&data), sizeof(data));
            
//             string s_data = org->getSpecies();
//             int s_size = s_data.size();
//             my_file.write(reinterpret_cast<const char*>(&s_size), sizeof(s_size));
//             my_file.write(s_data.c_str(), s_size);
//         }
//     }
// }

// void World::readWorld(const string& fileName)
// {
//     ifstream my_file(fileName, ios::binary);
//     if (my_file.is_open()) {
//         // Clear existing organisms
//         for (auto org : organisms) {
//             delete org;
//         }
//         organisms.clear();

//         my_file.read(reinterpret_cast<char*>(&worldX), sizeof(worldX));
//         my_file.read(reinterpret_cast<char*>(&worldY), sizeof(worldY));
//         my_file.read(reinterpret_cast<char*>(&turn), sizeof(turn));
        
//         int orgs_size;
//         my_file.read(reinterpret_cast<char*>(&orgs_size), sizeof(orgs_size));
        
//         for (int i = 0; i < orgs_size; i++) {
//             int power, pos_x, pos_y;
//             my_file.read(reinterpret_cast<char*>(&power), sizeof(power));
//             my_file.read(reinterpret_cast<char*>(&pos_x), sizeof(pos_x));
//             my_file.read(reinterpret_cast<char*>(&pos_y), sizeof(pos_y));
            
//             int s_size;
//             my_file.read(reinterpret_cast<char*>(&s_size), sizeof(s_size));
            
//             string species(s_size, '\0');
//             my_file.read(&species[0], s_size);
            
//             // Create appropriate organism based on species
//             Organism* org = nullptr;
//             if (species == "Grass") {
//                 org = new Grass(Position(pos_x, pos_y), this);
//             }
//             // Add other species here...
            
//             if (org) {
//                 org->setPower(power);
//                 addOrganism(org);
//             }
//         }
//     }
// }

// string World::toString() const
// {
//     string result = "\nturn: " + to_string(turn) + "\n";
    
//     for (int y = 0; y < worldY; ++y) {
//         for (int x = 0; x < worldX; ++x) {
//             string spec = getOrganismFromPosition(x, y);
//             result += (spec.empty() ? string(1, separator) : spec);
//         }
//         result += "\n";
//     }
//     return result;
// }

// Position World::findEmptyAdjacentPosition(Position position) const {
//     const vector<Position> directions = {
//         Position(0, 1), Position(1, 0), Position(0, -1), Position(-1, 0)
//     };
    
//     // Randomize direction checking
//     vector<Position> shuffled = directions;
//     random_shuffle(shuffled.begin(), shuffled.end());
    
//     for (const auto& dir : shuffled) {
//         Position newPos(position.getX() + dir.getX(), 
//                        position.getY() + dir.getY());
        
//         if (isPositionOnWorld(newPos.getX(), newPos.getY())) {
//             bool occupied = false;
//             for (const auto& org : organisms) {
//                 if (org->getPosition() == newPos) {
//                     occupied = true;
//                     break;
//                 }
//             }
//             if (!occupied) {
//                 return newPos;
//             }
//         }
//     }
//     return Position(-1, -1);
// }






#include "World.h"
#include <iostream>
#include <fstream>
#include <algorithm> // dla remove_if
#include "Animal.h"
#include "Plant.h"
#include "Grass.h"
#include <string>
#include <fstream>
#include "Sheep.h"
#include <cstdlib>
#include "Dandelion.h"
#include "Wolf.h"

World::World(int x, int y) : worldX(x), worldY(y) {}

void World::addOrganism(Organism* organism) {
    if (organism != nullptr) {
        organisms.push_back(organism);
    } else {
        std::cerr << "Error: Trying to add a null organism!" << std::endl;
    }
}

//bez rozprestrzeniania trawy
// void World::makeTurn() {
//     std::vector<Position> newPositions;
//     int numberOfNewPositions;
//     int randomIndex;

//     srand(time(0));
//     for (auto& org : organisms) {
//         if (dynamic_cast<Animal*>(org)) { // Tylko zwierzęta się poruszają
//             Animal* animal = dynamic_cast<Animal*>(org);
//             newPositions = getVectorOfFreePositionsAround(animal->getPosition());
//             numberOfNewPositions = newPositions.size();
//             if (numberOfNewPositions > 0) {
//                 randomIndex = rand() % numberOfNewPositions;
//                 animal->move(newPositions[randomIndex].getX() - animal->getPosition().getX(),
//                             newPositions[randomIndex].getY() - animal->getPosition().getY());
//             }
//         }
//     }
//     turn++;
// }

//bez mleczka 
// void World::makeTurn() {
//     std::vector<Position> newPositions;
//     int numberOfNewPositions;
//     int randomIndex;

//     srand(time(0));

//     // Przechodzimy przez wszystkie organizmy w świecie
//     for (auto& org : organisms) {
//         if (dynamic_cast<Animal*>(org)) { // Tylko zwierzęta się poruszają
//             Animal* animal = dynamic_cast<Animal*>(org);
//             newPositions = getVectorOfFreePositionsAround(animal->getPosition());
//             numberOfNewPositions = newPositions.size();
//             if (numberOfNewPositions > 0) {
//                 randomIndex = rand() % numberOfNewPositions;
//                 animal->move(newPositions[randomIndex].getX() - animal->getPosition().getX(),
//                             newPositions[randomIndex].getY() - animal->getPosition().getY());
//             }
//         } 
//         else if (dynamic_cast<Grass*>(org)) {  // Jeśli organizm jest trawą
//             Grass* grass = dynamic_cast<Grass*>(org);
//             grass->spread();  // Trawa rozprzestrzenia się
//         }

//     }

//     turn++;  // Zwiększamy numer tury
// }

void World::makeTurn() {
    std::vector<Position> newPositions;
    int numberOfNewPositions;
    int randomIndex;

    srand(time(0));

    // Przechodzimy przez wszystkie organizmy w świecie
    for (auto& org : organisms) {
        if (dynamic_cast<Animal*>(org)) { // Tylko zwierzęta się poruszają
            Animal* animal = dynamic_cast<Animal*>(org);
            newPositions = getVectorOfFreePositionsAround(animal->getPosition());
            numberOfNewPositions = newPositions.size();
            if (numberOfNewPositions > 0) {
                randomIndex = rand() % numberOfNewPositions;
                animal->move(newPositions[randomIndex].getX() - animal->getPosition().getX(),
                            newPositions[randomIndex].getY() - animal->getPosition().getY());
            }
        } 
        else if (dynamic_cast<Plant*>(org)) {  // Jeśli organizm jest trawą
            Plant* plant = dynamic_cast<Plant*>(org);
            plant->spread();  // Trawa rozprzestrzenia się
        }

    }

    turn++;  // Zwiększamy numer tury
}


std::string World::toString() const {
    std::string result = "Turn: " + std::to_string(turn) + "\n";
    for (int y = 0; y < worldY; ++y) {
        for (int x = 0; x < worldX; ++x) {
            bool organismFound = false;
            for (auto org : organisms) {
                if (org->getPosition().getX() == x && org->getPosition().getY() == y) {
                    result += org->toString();
                    organismFound = true;
                    break;
                }
            }
            if (!organismFound) {
                result += ".";  // Pusta przestrzeń
            }
        }
        result += "\n";
    }
    return result;
}

std::vector<Position> World::getVectorOfFreePositionsAround(Position position) {
    std::vector<Position> freePositions;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx != 0 || dy != 0) {
                Position newPos(position.getX() + dx, position.getY() + dy);
                if (isPositionFree(newPos)) {
                    freePositions.push_back(newPos);
                }
            }
        }
    }
    return freePositions;
}

bool World::isPositionFree(Position position) {
    for (auto org : organisms) {
        if (org->getPosition().getX() == position.getX() && org->getPosition().getY() == position.getY()) {
            return false;
        }
    }
    return true;
}

void World::writeWorld(std::string fileName) {
    std::fstream my_file;
    my_file.open(fileName, std::ios::out | std::ios::binary);
    if (my_file.is_open()) {
        my_file.write((char*)&this->worldX, sizeof(int));
        my_file.write((char*)&this->worldY, sizeof(int));
        my_file.write((char*)&this->turn, sizeof(int));

        int orgs_size = this->organisms.size();
        my_file.write((char*)&orgs_size, sizeof(int));

        for (int i = 0; i < orgs_size; i++) {
            int data;
            data = this->organisms[i]->getPower();  // Zmiana kropki na strzałkę
            my_file.write((char*)&data, sizeof(int));

            data = this->organisms[i]->getPosition().getX();  // Zmiana kropki na strzałkę
            my_file.write((char*)&data, sizeof(int));

            data = this->organisms[i]->getPosition().getY();  // Zmiana kropki na strzałkę
            my_file.write((char*)&data, sizeof(int));

            std::string s_data = this->organisms[i]->getSpecies();  // Zmiana kropki na strzałkę
            int s_size = s_data.size();
            my_file.write((char*)&s_size, sizeof(int));
            my_file.write(s_data.data(), s_data.size());
        }

        my_file.close();
    }
}


void World::readWorld(std::string fileName) {
    std::fstream my_file;
    my_file.open(fileName, std::ios::in | std::ios::binary);

    if (my_file.is_open()) {
        int result;

        // Read basic world data
        my_file.read((char*)&result, sizeof(int));
        this->worldX = result;
        my_file.read((char*)&result, sizeof(int));
        this->worldY = result;
        my_file.read((char*)&result, sizeof(int));
        this->turn = result;
        my_file.read((char*)&result, sizeof(int));
        int orgs_size = result;

        // Vector of pointers to organisms
        std::vector<Organism*> new_organisms;

        for (int i = 0; i < orgs_size; ++i) {
            int power;
            my_file.read((char*)&result, sizeof(int));
            power = result;

            int pos_x, pos_y;
            my_file.read((char*)&result, sizeof(int));
            pos_x = result;
            my_file.read((char*)&result, sizeof(int));
            pos_y = result;
            Position pos{ pos_x, pos_y };

            int s_size;
            my_file.read((char*)&result, sizeof(int));
            s_size = result;

            std::string species;
            species.resize(s_size);
            my_file.read(&species[0], s_size);

            Organism* org = nullptr;

            if (species == "Sheep") {
                org = new Sheep(power, pos, species, this);
            } else if (species == "Grass") {
                org = new Grass(power, pos, species, this);
			} else if (species == "Dandelion") {
                org = new Dandelion(power, pos, species, this);
            } else if (species == "Wolf") {
                org = new Wolf(power, pos, species, this);
            } else {
                std::cerr << "Unknown species: " << species << std::endl;
                continue; // skip unknown
            }

            new_organisms.push_back(org);
        }

        this->organisms = new_organisms;
        my_file.close();
    } else {
        std::cerr << "Failed to open file: " << fileName << std::endl;
    }
}




Position World::findEmptyAdjacentPosition(Position position) {
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;  // Pomijamy samą pozycję

            Position newPos(position.getX() + dx, position.getY() + dy);
            if (isPositionFree(newPos)) {
                return newPos;  // Zwracamy pierwszą wolną pozycję
            }
        }
    }
    return Position(-1, -1);  // Brak wolnej pozycji
}

Organism* World::getOrganismAt(const Position& pos) const {
    for (Organism* org : organisms) {
        if (org->getPosition() == pos && org->isAlive()) {
            std::cout << "Found organism at: " << pos.toString() << ", Species: " << org->getSpecies() << std::endl;
            return org;
        }
    }
    std::cout << "No organism found at: " << pos.toString() << std::endl;
    return nullptr;  // jeśli brak organizmu na tej pozycji
}

Organism* World::getOrganismFromPosition(Position pos) {
    for (auto& organism : organisms) {
        if (organism->getPosition() == pos) {
            return organism;  // Zwracamy organizm, który jest na tej pozycji
        }
    }
    return nullptr;  // Zwracamy nullptr, jeśli na tej pozycji nie ma organizmu
}


void World::removeOrganismAtPosition(Position pos) {
    for (auto it = organisms.begin(); it != organisms.end(); ++it) {
        Organism* organism = *it;
        if (organism->getPosition() == pos) {
            std::cout << "Removing organism at: " << pos.toString() << std::endl;  // Debugowanie
            organisms.erase(it);  // Usuwamy organizm z planszy
            break;
        }
    }
}
