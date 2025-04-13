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
    Position prevPos = getPosition();  // Zapamiętujemy poprzednią pozycję

    Position newPos = getPosition();
    newPos.move(dx, dy);  // Przemieszczamy owcę

    if (world != nullptr) {
        // Sprawdzamy, co jest na nowej pozycji
        Organism* organismAtNewPos = world->getOrganismFromPosition(newPos);

        // Jeśli na nowej pozycji znajduje się trawa, to owca ją zjada
        if (organismAtNewPos != nullptr && organismAtNewPos->getSpecies() == "Sheep") {
            std::cout << "Wolf at " << newPos.toString() << " eats sheep!" << std::endl;
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
                if (organismAtNeighbor != nullptr && organismAtNeighbor->getSpecies() == "Sheep") {
                    std::cout << "Wolf at " << newPos.toString() << " eats sheep at neighboring position " << neighborPos.toString() << "!" << std::endl;
                    world->removeOrganismAtPosition(neighborPos);  // Usuwamy trawę z sąsiedniej pozycji
                    break;  // Owca może jeść tylko jedną trawę, więc przerywamy pętlę
                }
            }
        }
    }

    setPosition(newPos);  // Ustawiamy nową pozycję owcy
}
