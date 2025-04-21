
#include "Dandelion.h"
#include "World.h"
#include <iostream>
#include "Sheep.h"


// Dandelion::Dandelion(int power, Position position, World* world)
//     : Plant(0, position, world) {
//         setSpecies("Dandelion");
//         setInitiative(0);
//         setLiveLength(6);
//         setPowerToReproduce(2);
//         setSign('D');
// }

// Dandelion::Dandelion(int power, Position position, std::string species, World* world)
//     : Plant(0, position, world) {
//         setSpecies("Dandelion");
//         setInitiative(0);
//         setLiveLength(6);
//         setPowerToReproduce(2);
//         setSign('D');
// }

// Dandelion::Dandelion()
//     : Plant(0, Position(0, 0), nullptr) {
//         setSpecies("Dandelion");
//         setInitiative(0);
//         setLiveLength(6);
//         setPowerToReproduce(2);
//         setSign('D');
// }

Dandelion::Dandelion(int power, Position position, World* world)
    : Plant(0, position, world) {
    initializeDandelion();  // Wywołanie funkcji pomocniczej
}

Dandelion::Dandelion(int power, Position position, std::string species, World* world)
    : Plant(0, position, world) {
    setSpecies(species);  // Ustawienie konkretnego gatunku
    initializeDandelion();  // Wywołanie funkcji pomocniczej
}

Dandelion::Dandelion()
    : Plant(0, Position(0, 0), nullptr) {
    initializeDandelion();  // Wywołanie funkcji pomocniczej
}
void Dandelion::initializeDandelion() {
    setSpecies("Dandelion");
    setInitiative(0);
    setLiveLength(6);
    setPowerToReproduce(2);
    setSign('D');
}

// void Dandelion::spread() {
//     if (this->getLiveLength() <= 0) return;

//     if (getWorld() == nullptr) {
//         std::cerr << "World is not initialized!" << std::endl;
//         return;
//     }

//     // Lista możliwych pozycji, na które trawa może się rozprzestrzenić
//     std::vector<Position> adjacentPositions = {
//         Position(getPosition().getX() - 1, getPosition().getY()), // Lewa
//         Position(getPosition().getX() + 1, getPosition().getY()), // Prawa
//         Position(getPosition().getX(), getPosition().getY() - 1), // Górna
//         Position(getPosition().getX(), getPosition().getY() + 1)  // Dolna
//     };

//     // Iteracja po sąsiednich pozycjach
//     for (auto& adjacentPos : adjacentPositions) {
//         // Sprawdź, czy sąsiednia pozycja jest w obrębie planszy
//         if (adjacentPos.isValid()) {
//             // Sprawdź, czy na tej pozycji nie ma innego organizmu
//             Organism* organismAtPos = getWorld()->getOrganismFromPosition(adjacentPos);

//             if (organismAtPos == nullptr) {
//                 // Jeśli pozycja jest wolna, rozprzestrzenić trawę
//                 getWorld()->addOrganism(new Dandelion(3, adjacentPos, getWorld()));
//                 std::cout << "Dandelion spread to position: " << adjacentPos.toString() << std::endl;
//                 break;  // Tylko jedna trawa rozprzestrzenia się w tej turze
//             } 
//         }
//     }
// }


void Dandelion::spread() {
    if (this->getLiveLength() <= 0) return;

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



// void Dandelion::collision(Organism* other) {
//     if (getLiveLength() <= 0) return;

//     this->setLiveLength(0);
// }

void Dandelion::collision(Organism* other) {
    if (getLiveLength() <= 0) return;

    // Sprawdzamy, czy "other" jest obiektem typu "Sheep"
    Sheep* sheep = dynamic_cast<Sheep*>(other);  // Próba rzutowania na typ "Sheep"
    
    if (sheep != nullptr) {
        // Jeśli rzutowanie się udało, to znaczy, że "other" to obiekt typu "Sheep"
        this->setLiveLength(0);  // Dandelion umiera
    }
    // Jeśli to nie jest owca, nie robimy nic
}

