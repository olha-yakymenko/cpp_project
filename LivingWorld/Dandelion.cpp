
#include "Dandelion.h"
#include "World.h"
#include <iostream>

Dandelion::Dandelion(int power, Position position, World* world)
    : Plant(0, position, world) {
        setSpecies("Dandelion");
        setInitiative(0);
        setLiveLength(6);
        setPowerToReproduce(2);
        setSign('D');
}

Dandelion::Dandelion(int power, Position position, std::string species, World* world)
    : Plant(0, position, world) {
        setSpecies("Dandelion");
        setInitiative(0);
        setLiveLength(6);
        setPowerToReproduce(2);
        setSign('D');
}

Dandelion::Dandelion()
    : Plant(0, Position(0, 0), nullptr) {
        setSpecies("Dandelion");
        setInitiative(0);
        setLiveLength(6);
        setPowerToReproduce(2);
        setSign('D');
}

void Dandelion::spread() {
    if (getWorld() == nullptr) {
        std::cerr << "World is not initialized!" << std::endl;
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
                getWorld()->addOrganism(new Dandelion(3, adjacentPos, getWorld()));
                std::cout << "Dandelion spread to position: " << adjacentPos.toString() << std::endl;
                break;  // Tylko jedna trawa rozprzestrzenia się w tej turze
            } 
        }
    }
}


Dandelion* Dandelion::clone() const {
    return new Dandelion(*this);
}

std::string Dandelion::toString() const {
    return "Dandelion at " + getPosition().toString();
}


