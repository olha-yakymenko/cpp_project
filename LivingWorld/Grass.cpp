// #include "Grass.h"
// #include "World.h"

// // Konstruktor klasy Grass
// Grass::Grass(int power, Position position, World* world) : Plant(power, position, world) {
//     setSpecies("Grass");
//     setSign('G');
// }

// // Reprezentacja obiektu Grass w postaci tekstu
// std::string Grass::toString() const {
//     return "Grass at " + getPosition().toString();
// }

// void Grass::spread() {
//     if (getWorld()) {
//         Position newPos = getWorld()->findEmptyAdjacentPosition(getPosition());
//         if (newPos.isValid()) {
//             getWorld()->addOrganism(new Grass(3, newPos, getWorld()));  // Tworzymy nową roślinę
//         }
//     }
// }


// // Klonowanie obiektu Grass
// Grass* Grass::clone() const {
//     return new Grass(*this);
// }




#include "Grass.h"
#include "World.h"
#include <iostream>
#include "Animal.h"

Grass::Grass(int power, Position position, World* world)
    : Plant(power, position, world) {
        setSpecies("Grass");
        setInitiative(0);
        setLiveLength(3);
        setPowerToReproduce(3);
        setSign('G');
}

Grass::Grass(int power, Position position, std::string species, World* world)
    : Plant(power, position, world) {
        setSpecies("Grass");
        setInitiative(0);
        setLiveLength(3);
        setPowerToReproduce(3);
        setSign('G');
}

Grass::Grass()
    : Plant(3, Position(0, 0), nullptr) {
        setSpecies("Grass");
        setInitiative(0);
        setLiveLength(3);
        setPowerToReproduce(3);
        setSign('G');
}

// void Grass::spread() {
//     if (getWorld()) {
//         Position newPos = getWorld()->findEmptyAdjacentPosition(getPosition());
//         if (newPos.isValid()) {
//             getWorld()->addOrganism(new Grass(3, newPos, getWorld()));
//         }
//     }
// }

// void Grass::spread() {
//     if (getWorld()) {
//         Position newPos = getWorld()->findEmptyAdjacentPosition(getPosition());
//         if (newPos.isValid()) {
//             // Rozmnażanie trawy w nowej pozycji
//             getWorld()->addOrganism(new Grass(3, newPos, getWorld()));
//         }
//     }
// }
void Grass::spread() {
    if (getLiveLength() <= 0) return;

    if (getWorld() == nullptr) {
        std::cerr << "trawa: World is not initialized!" << std::endl;
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

            // Jeśli nie ma organizmu lub jest inny organizm, rozprzestrzenić trawę
            if (organismAtPos == nullptr || dynamic_cast<Animal*>(organismAtPos)) {
                // Jeśli pozycja jest wolna lub zajmowana przez inną trawę, rozprzestrzenić trawę
                if (organismAtPos == nullptr) {
                    getWorld()->addOrganism(new Grass(3, adjacentPos, getWorld()));
                    std::cout << "Grass spread to position: " << adjacentPos.toString() << std::endl;
                } else {
                    std::cout << "Grass tried to spread to position: " << adjacentPos.toString() << ", but it's already occupied by Grass." << std::endl;
                }
                break;  // Tylko jedna trawa rozprzestrzenia się w tej turze
            } 
        }
    }
}

Grass* Grass::clone() const {
    return new Grass(*this);
}

std::string Grass::toString() const {
    return "Grass at " + getPosition().toString();
}

void Grass::collision(Organism* other) {
    if (getLiveLength() <= 0) return;

    this->setLiveLength(0);
}

