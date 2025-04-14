
#include "Toadstool.h"
#include "World.h"
#include <iostream>

Toadstool::Toadstool(int power, Position position, World* world)
    : Plant(0, position, world) {
        setSpecies("Toadstool");
        setInitiative(0);
        setLiveLength(12);
        setPowerToReproduce(4);
        setSign('T');
}

Toadstool::Toadstool(int power, Position position, std::string species, World* world)
    : Plant(0, position, world) {
        setSpecies("Toadstool");
        setInitiative(0);
        setLiveLength(12);
        setPowerToReproduce(4);
        setSign('T');
}

Toadstool::Toadstool()
    : Plant(0, Position(0, 0), nullptr) {
        setSpecies("Toadstool");
        setInitiative(0);
        setLiveLength(12);
        setPowerToReproduce(4);
        setSign('T');
}

void Toadstool::spread() {
    if (getLiveLength() <= 0) return;

    if (getWorld() == nullptr) {
        std::cerr << "muchomor : World is not initialized!" << std::endl;
        return;
    }

    // Lista możliwych pozycji, na które trawa może się rozprzestrzenić
    std::vector<Position> adjacentPositions = {
        Position(getPosition().getX() - 1, getPosition().getY()), // Lewa
        Position(getPosition().getX() + 1, getPosition().getY()), // Prawa
        Position(getPosition().getX(), getPosition().getY() - 1), // Górna
        Position(getPosition().getX(), getPosition().getY() + 1)  // Dolna
    };

    // Iteracja po sąsiednich pozycjach
    for (auto& adjacentPos : adjacentPositions) {
        // Sprawdź, czy sąsiednia pozycja jest w obrębie planszy
        if (adjacentPos.isValid()) {
            // Sprawdź, czy na tej pozycji nie ma innego organizmu
            Organism* organismAtPos = getWorld()->getOrganismFromPosition(adjacentPos);

            if (organismAtPos == nullptr) {
                // Jeśli pozycja jest wolna, rozprzestrzenić trawę
                getWorld()->addOrganism(new Toadstool(3, adjacentPos, getWorld()));
                std::cout << "Toadstool spread to position: " << adjacentPos.toString() << std::endl;
                break;  // Tylko jedna trawa rozprzestrzenia się w tej turze
            } 
        }
    }
}


Toadstool* Toadstool::clone() const {
    return new Toadstool(*this);
}

std::string Toadstool::toString() const {
    return "Toadstool at " + getPosition().toString();
}

void Toadstool::collision(Organism* attacker) {
    if (getLiveLength() <= 0) return;

    std::string species = attacker->getSpecies();
    if (species == "Grass" or species=="Dandelion") {
        
    } else{
    std::cout << attacker->toString() << " at position " << attacker->getPosition().toString()
              << " ate a Toadstool!" << this->getPosition().toString() << std::endl;
    this->setLiveLength(0); 
    } // Muchomor umiera po zjedzeniu
}
// Sheep at (5, 1) at position (5, 1) ate a Toadstool!(5, 0)