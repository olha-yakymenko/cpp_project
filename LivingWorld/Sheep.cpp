// #include "Sheep.h"

// Sheep::Sheep(Position position, World* world)
//     : Animal(3, position, world) {
//     this->setSpecies("Sheep");
//     this->setInitiative(3);
//     this->setLiveLength(10);
//     this->setPowerToReproduce(6);
//     this->setSign('S');
// }

// Sheep::Sheep()
//     : Animal(3, Position(0, 0), nullptr) {
//     this->setSpecies("Sheep");
//     this->setInitiative(3);
//     this->setLiveLength(10);
//     this->setPowerToReproduce(6);
//     this->setSign('S');
// }

// Animal* Sheep::clone() const {
//     return new Sheep(*this);
// }


// std::string Sheep::toString() const {
//     return "Sheep at (" + std::to_string(getPosition().getX()) + ", " + std::to_string(getPosition().getY()) + ")";
// }



#include "Sheep.h"
#include "World.h"
#include <iostream>

Sheep::Sheep(Position position, World* world)
    : Animal(3, position, world) {
    setSpecies("Sheep");
    setInitiative(3);
    setLiveLength(10);
    setPowerToReproduce(6);
    setSign('S');
}

Sheep::Sheep(int power, Position position, std::string species, World* world)
    : Animal(power, position, world) {
    setSpecies(species);
    setInitiative(3);
    setLiveLength(10);
    setPowerToReproduce(6);
    setSign('S');
}

Sheep::Sheep()
    : Animal(3, Position(0, 0), nullptr) {
    setSpecies("Sheep");
    setInitiative(3);
    setLiveLength(10);
    setPowerToReproduce(6);
    setSign('S');
}

Animal* Sheep::clone() const {
    return new Sheep(*this);
}

std::string Sheep::toString() const {
    return "Sheep at (" + std::to_string(getPosition().getX()) + ", " + std::to_string(getPosition().getY()) + ")";
}


// void Sheep::move(int dx, int dy) {
//     Position prevPos = getPosition();  // Zapamiętujemy poprzednią pozycję

//     Position newPos = getPosition();
//     newPos.move(dx, dy);  // Przemieszczamy owcę

//     if (world != nullptr) {
//         // Sprawdzamy, co jest na nowej pozycji
//         Organism* organismAtNewPos = world->getOrganismFromPosition(newPos);
//         std::cout << "jestem";
//         // Dodajemy komunikat debugujący, który wyświetli gatunek organizmu na tej pozycji
//         if (organismAtNewPos != nullptr) {
//             std::cout << "Organism at " << newPos.toString() << ": " << organismAtNewPos->getSpecies() << std::endl;
//         }

//         if (organismAtNewPos != nullptr) {
//             std::cout << organismAtNewPos->getSpecies() << "aaa";
//         } else {
//             std::cout << "No organism at this position" << std::endl;
//         }
        
//         // Jeśli na nowej pozycji znajduje się trawa, to owca ją zjada
//         if (organismAtNewPos != nullptr && organismAtNewPos->getSpecies() == "Grass") {
//             std::cout << "Sheep at " << newPos.toString() << " eats grass!" << std::endl;
//             world->removeOrganismAtPosition(newPos);  // Usuwamy trawę z planszy
//         }
//     }

//     setPosition(newPos);  // Ustawiamy nową pozycję owcy
// }


void Sheep::move(int dx, int dy) {
    Position prevPos = getPosition();  // Zapamiętujemy poprzednią pozycję

    Position newPos = getPosition();
    newPos.move(dx, dy);  // Przemieszczamy owcę

    if (world != nullptr) {
        // Sprawdzamy, co jest na nowej pozycji
        Organism* organismAtNewPos = world->getOrganismFromPosition(newPos);

        // Jeśli na nowej pozycji znajduje się trawa, to owca ją zjada
        if (organismAtNewPos != nullptr && organismAtNewPos->getSpecies() == "Grass") {
            std::cout << "Sheep at " << newPos.toString() << " eats grass!" << std::endl;
            world->removeOrganismAtPosition(newPos);  // Usuwamy trawę z planszy
        }

        // Sprawdzamy sąsiednie pozycje (4 kierunki)
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;  // Pomijamy centralną pozycję (tę, na której jest owca)

                Position neighborPos = newPos;
                neighborPos.move(i, j);  // Przesuwamy się do sąsiedniej pozycji

                // Sprawdzamy, czy w sąsiedniej pozycji znajduje się trawa
                Organism* organismAtNeighbor = world->getOrganismFromPosition(neighborPos);
                if (organismAtNeighbor != nullptr && organismAtNeighbor->getSpecies() == "Grass") {
                    std::cout << "Sheep at " << newPos.toString() << " eats grass at neighboring position " << neighborPos.toString() << "!" << std::endl;
                    world->removeOrganismAtPosition(neighborPos);  // Usuwamy trawę z sąsiedniej pozycji
                    break;  // Owca może jeść tylko jedną trawę, więc przerywamy pętlę
                }
            }
        }
    }

    setPosition(newPos);  // Ustawiamy nową pozycję owcy
}
