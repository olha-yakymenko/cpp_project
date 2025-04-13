#include "Wolf.h"
#include "World.h"
#include <iostream>

Wolf::Wolf(Position position, World* world)
    : Animal(8, position, world) {
    setSpecies("Wolf");
    setInitiative(5);
    setLiveLength(20);
    setPowerToReproduce(16);
    setSign('W');
}

Wolf::Wolf(int power, Position position, std::string species, World* world)
    : Animal(power, position, world) {
        setSpecies("Wolf");
        setInitiative(5);
        setLiveLength(20);
        setPowerToReproduce(16);
        setSign('W');
}

Wolf::Wolf()
    : Animal(3, Position(0, 0), nullptr) {
        setSpecies("Wolf");
        setInitiative(5);
        setLiveLength(20);
        setPowerToReproduce(16);
        setSign('W');
}

Animal* Wolf::clone() const {
    return new Wolf(*this);
}

std::string Wolf::toString() const {
    return "Wolf at (" + std::to_string(getPosition().getX()) + ", " + std::to_string(getPosition().getY()) + ")";
}

void Wolf::move(int dx, int dy) {
    if (getLiveLength() <= 0) return;

    Position newPos = getPosition();
    newPos.move(dx, dy);  // Przesuwamy się

    if (world != nullptr) {
        Organism* organismAtNewPos = world->getOrganismFromPosition(newPos);

        // Jeśli coś jest na nowej pozycji – kolizja!
        if (organismAtNewPos != nullptr) {
            this->collision(organismAtNewPos);  // Wilk reaguje na zderzenie
        } else {
            setPosition(newPos);  // Jeśli pusto, po prostu się przemieść
        }
    }
}



void Wolf::collision(Organism* other) {
    if (other == nullptr) return;

    std::string species = other->getSpecies();

    if (species == "Sheep") {
        // Wilk zjada owcę
        std::cout << "Wolf at " << getPosition().toString() << " eats sheep at " << other->getPosition().toString() << "!" << std::endl;
        setPower(getPower() + other->getPower());  // Wilk zwiększa swoją moc
        setPosition(other->getPosition());  // Wilk przejmuje pozycję owcy
    } 

    else if (species == "Toadstool") {
        // Wilk je trujące grzyby (jeśli tak założyliśmy w mechanice)
        std::cout << "Wolf at " << getPosition().toString() << " eats poisonous mushroom and dies!" << other->getPosition().toString() << std::endl;
        setLiveLength(0);  // Wilk umiera po zjedzeniu trującego grzyba
    } 
    else if (species == "Wolf") {
        // Wilk spotyka innego wilka (można dodać odpowiednią reakcję, np. walka lub ignorowanie)
        std::cout << "Wolf at " << getPosition().toString() << " encounters another wolf!" << std::endl;
        // Można dodać inne reakcje na spotkanie z innym wilkiem, np. walkę
    }
    else {
        // W przypadku innych organizmów, wilk nic nie robi
        std::cout << "Wolf at " << getPosition().toString() << " encounters " << species << ", but does nothing." << std::endl;
    }
}
