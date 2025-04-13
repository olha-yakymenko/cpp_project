// #pragma once
// #include <string>
// #include "Position.h"

// using namespace std;

// class Organism
// {
// private:
// 	int power;
// 	Position position;
// 	string species;
// public:
// 	Organism(int power, Position position);
// 	Organism() : power(0), position(0, 0), species("O") {};

// 	int getPower();
// 	void setPower(int power);
// 	Position getPosition();
// 	void setPosition(Position position);
// 	string getSpecies();
// 	void setSpecies(string spec);

// 	string toString();

// 	virtual void move(int dx, int dy);

// };





// #pragma once

// #include <string>
// #include "Position.h"

// // Forward declaration of World class to avoid circular dependency
// class World;

// using namespace std;

// class Organism
// {
// private:
//     int power;
//     Position position;
//     string species;
//     int initiative;
//     int liveLength;
//     int powerToReproduce;
// 	int initialPowerToReproduce;
//     char sign;
// protected:
//     World* world; // Pointer to the World object the Organism belongs to

// public:
//     // Constructor with the World pointer
// 	Organism(int power, Position position, string species, int initiative, int liveLength, int powerToReproduce, char sign, World* world);

//     // Default constructor
//     Organism();

// 	virtual ~Organism() = default;

// 	virtual Organism* clone() const = 0;  // Pure virtual function
//     int getInitialPowerToReproduce() const { return initialPowerToReproduce; }

//     // Getters and setters
//     int getPower();
//     void setPower(int power);

//     Position getPosition() const { return position; }
//     void setPosition(Position position);

//     string getSpecies();
//     void setSpecies(string species);

//     int getInitiative();
//     void setInitiative(int initiative);

//     int getLiveLength();
//     void setLiveLength(int liveLength);

//     int getPowerToReproduce();
//     void setPowerToReproduce(int powerToReproduce);

//     char getSign();
//     void setSign(char sign);

//     World* getWorld(); // Getter for accessing the World object
// 	void setWorld(World* world) { this->world = world; }
//     // Function to describe the organism
//     // Organism.h
// 	virtual std::string toString() const {
// 		return species + " at " + position.toString();
// 	}

//     // Method to move the organism
//     // virtual void move(int dx, int dy);
// 	virtual void move(int dx, int dy) = 0;

//     // Increase organism's power
//     void increasePower();

//     // Decrease organism's life length
//     void decreaseLife();

//     // Check if the organism is still alive
//     bool isAlive();
// };




//newirt
// #pragma once

// #include "Position.h"
// #include <string>

// class World;  // Forward declaration

// class Organism {
// public:
//     Organism();
//     Organism(int power, Position position, std::string species,
//              int initiative, int liveLength, int powerToReproduce,
//              char sign, World* world);

//     virtual ~Organism() = default;

//     virtual void move(int dx, int dy) = 0;
//     virtual Organism* clone() const = 0;
// 	virtual void handleCollision(Organism* other);  // dodajesz w public:


//     // Gettery i settery
//     int getPower() const;
//     void setPower(int power);

//     Position getPosition() const;
//     void setPosition(Position position);

//     virtual void spread();  // Implementacja zależna od klasy dziedziczącej
//     virtual std::string toString() const;

//     std::string getSpecies() const;
//     void setSpecies(const std::string& spec);

//     int getInitiative() const;
//     void setInitiative(int initiative);

//     int getLiveLength() const;
//     void setLiveLength(int liveLength);

//     int getPowerToReproduce() const;
//     void setPowerToReproduce(int powerToReproduce);

//     char getSign() const;
//     void setSign(char sign);

//     World* getWorld() const;
//     void setWorld(World* world);

//     bool isAlive() const;
//     void increasePower();
//     void decreaseLife();

// protected:
//     int power;
//     Position position;
//     std::string species;
//     int initiative;
//     int liveLength;
//     int powerToReproduce;
//     int initialPowerToReproduce; // Dodana zmienna
//     char sign;
//     World* world;
// };


#pragma once

#include "Position.h"
#include <string>

class World;  // Forward declaration

class Organism {
public:
    // Konstruktor domyślny
    Organism();
    
    // Konstruktor z parametrami
    Organism(int power, Position position, std::string species,
		int initiative, int liveLength, int powerToReproduce,
		char sign, World* world);

    // Wirtualny destruktor
    virtual ~Organism() = default;

    // Wirtualne metody, które muszą zostać zaimplementowane w klasach dziedziczących
    virtual void move(int dx, int dy) = 0;
    virtual Organism* clone() const = 0;
    virtual void handleCollision(Organism* other);  // Wirtualna metoda

    // Gettery i settery
    virtual int getPower() const;
    virtual void setPower(int power);

    virtual Position getPosition() const;
    virtual void setPosition(Position position);

    // Metoda spread() jest wirtualna
    virtual void spread();  // Implementacja zależna od klasy dziedziczącej

    // Metoda toString() jest wirtualna
    virtual std::string toString() const;

    // Gettery i settery dla pozostałych pól
    virtual std::string getSpecies() const;
    virtual void setSpecies(const std::string& spec);

    virtual int getInitiative() const;
    virtual void setInitiative(int initiative);

    virtual int getLiveLength() const;
    virtual void setLiveLength(int liveLength);

    virtual int getPowerToReproduce() const;
    virtual void setPowerToReproduce(int powerToReproduce);

    virtual char getSign() const;
    virtual void setSign(char sign);

    virtual World* getWorld() const;
    virtual void setWorld(World* world);

    virtual bool isAlive() const;
    virtual void increasePower();
    virtual void decreaseLife();

	virtual void collision(Organism* other) = 0;


protected:
    int power;
    Position position;
    std::string species;
    int initiative;
    int liveLength;
    int powerToReproduce;
    int initialPowerToReproduce; // Dodana zmienna
    char sign;
    World* world;
};
