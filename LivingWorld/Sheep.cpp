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

void Sheep::collision(Organism* other) {
    if (getLiveLength() <= 0) return;

    if (other == nullptr) return;

    std::string species = other->getSpecies();

    if (species == "Grass") {
        std::cout << "Sheep at " << getPosition().toString() << " eats grass!" << std::endl;
        setPower(getPower() + other->getPower());
    } else if (species == "Toadstool") {
        std::cout << "TUTAJ";
        std::cout << "Sheep at " << getPosition().toString() << " eats poisonous mushroom and dies!" << std::endl;
        setLiveLength(0);  // Owca umiera
    } else if (species == "Wolf") {
        std::cout << "Sheep at " << getPosition().toString() << " was eaten by a wolf!" << std::endl;
        setLiveLength(0);  // Owca umiera
    }
}

void Sheep::move(int dx, int dy) {
    if (getLiveLength() <= 0) return;

    Position prevPos = getPosition();
    Position newPos = prevPos;
    newPos.move(dx, dy);

    if (world != nullptr) {
        Organism* target = world->getOrganismFromPosition(newPos);
        collision(target);  // wykonaj zderzenie (np. zjedzenie, śmierć)
        setPosition(newPos);  // ruszamy owcę
    } else {
        setPosition(newPos);
    }
}
