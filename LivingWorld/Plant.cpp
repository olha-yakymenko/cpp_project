#include "Plant.h"

Plant::Plant(int power, Position position, World* world)
    : Organism(power, position, "Plant", 0, 0, 1, 'P', world) {
    // Inicjalizowanie zmiennych dla rośliny
    x = position.getX();  // Jeśli masz gettery w klasie Position
    yn = position.getY();
    wcwidth = 50;   // Przykładowa szerokość
    height = 100;   // Przykładowa wysokość
}

// Konstruktor domyślny
Plant::Plant() : Organism(0, Position(0, 0), "Plant", 0, 0, 1, 'P', nullptr) {
    // Inicjalizowanie zmiennych domyślnych
    x = 100;        // Domyślna pozycja X
    yn = 200;       // Domyślna pozycja Y
    wcwidth = 50;   // Domyślna szerokość
    height = 100;   // Domyślna wysokość
}

void Plant::move(int dx, int dy) {
    Position newPos = getPosition();
    newPos.move(dx, dy);  // Przemieszczamy roślinę
    setPosition(newPos);   // Aktualizujemy pozycję
}


void Plant::spread() {
    // Logika rozprzestrzeniania dla rośliny
}

Organism* Plant::clone() const {
    return new Plant(*this);  // Tworzenie kopii rośliny
}

std::string Plant::toString() const {
    return species + " at (" + std::to_string(position.getX()) + ", " + std::to_string(position.getY()) + ")";
}


void Plant::collision(Organism* other) {
}

