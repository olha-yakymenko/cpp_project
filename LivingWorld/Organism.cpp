#include "Organism.h"
#include "World.h"

Organism::Organism() 
    : power(0), initiative(0), liveLength(0), powerToReproduce(0), 
      initialPowerToReproduce(0), sign(' '), world(nullptr) {}

Organism::Organism(int power, Position position, std::string species,
                   int initiative, int liveLength, int powerToReproduce,
                   char sign, World* world)
    : power(power), position(position), species(species),
      initiative(initiative), liveLength(liveLength), powerToReproduce(powerToReproduce),
      initialPowerToReproduce(powerToReproduce), sign(sign), world(world) {}

int Organism::getPower() const {
    return power;
}

void Organism::setPower(int power) {
    this->power = power;
}

Position Organism::getPosition() const {
    return position;
}

void Organism::setPosition(Position position) {
    this->position = position;
}

std::string Organism::getSpecies() const {
    return species;
}

void Organism::setSpecies(const std::string& species) {
    this->species = species;
}

int Organism::getInitiative() const {
    return initiative;
}

void Organism::setInitiative(int initiative) {
    this->initiative = initiative;
}

int Organism::getLiveLength() const {
    return liveLength;
}

void Organism::setLiveLength(int liveLength) {
    this->liveLength = liveLength;
}

int Organism::getPowerToReproduce() const {
    return powerToReproduce;
}

void Organism::setPowerToReproduce(int powerToReproduce) {
    this->powerToReproduce = powerToReproduce;
}

char Organism::getSign() const {
    return sign;
}

void Organism::setSign(char sign) {
    this->sign = sign;
}

World* Organism::getWorld() const {
    return world;
}

void Organism::setWorld(World* world) {
    this->world = world;
}

bool Organism::isAlive() const {
    return liveLength > 0;
}

void Organism::increasePower() {
    power++;
}

void Organism::decreaseLife() {
    liveLength--;
}

void Organism::spread() {
    // Implementacja zależna od konkretnego organizmu
    // Może obejmować reprodukcję organizmu, np. sprawdzanie sąsiednich wolnych pozycji
}

std::string Organism::toString() const {
    return species + " at (" + std::to_string(position.getX()) + "," + std::to_string(position.getY()) + ")";
}

void Organism::handleCollision(Organism* other) {
    // Tymczasowa implementacja – np. walka o przetrwanie
    if (this->getPower() >= other->getPower()) {
        other->setPower(0);  // inne ginie
    } else {
        this->setPower(0);   // ja ginę
    }
}
