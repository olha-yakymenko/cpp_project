#include "Animal.h"
#include "World.h"

Animal::Animal(int power, Position position, World* world)
    : Organism(power, position, "Animal", 5, 0, 2, 'A', world) {}

Animal::Animal() : Organism(0, Position(0, 0), "Animal", 5, 0, 2, 'A', nullptr) {}

// void Animal::move(int dx, int dy) {
//     // Ruch dla zwierzęcia
//     position.setX(position.getX() + dx);
//     position.setY(position.getY() + dy);
// }

void Animal::move(int dx, int dy) {
    previousPosition = position;  // Zapamiętaj obecną pozycję

    Position newPos = Position(position.getX() + dx, position.getY() + dy);

    // Jeśli istnieje świat
    if (world != nullptr) {
        Organism* encountered = world->getOrganismAt(newPos);  // zakładamy, że masz taką metodę

        if (encountered != nullptr) {
            this->handleCollision(encountered);  // zakładamy, że metoda np. zdefiniowana w Organism lub Animal
            return;
        }
    }

    position = newPos;  // Jeśli nie było kolizji, to porusz się
}


void Animal::spread() {
    // Logika rozprzestrzeniania dla zwierzęcia
}

Animal* Animal::clone() const {
    return new Animal(*this);  // Tworzenie kopii zwierzęcia
}

std::string Animal::toString() const {
    return species + " at (" + std::to_string(position.getX()) + ", " + std::to_string(position.getY()) + ")";
}


void Animal::collision(Organism* other) {
  
}
