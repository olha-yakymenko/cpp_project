#include "Animal.h"
#include "World.h"

Animal::Animal(int power, Position position, World* world)
    : Organism(power, position, "Animal", 5, 0, 2, 'A', world) {
    // Inicjalizowanie dodatkowych zmiennych
    x = position.getX();  // Jeśli masz gettery w klasie Position
    yn = position.getY();
    wcwidth = 50;   // Przykładowa szerokość
    height = 100;   // Przykładowa wysokość
}

// Konstruktor domyślny
Animal::Animal() : Organism(0, Position(0, 0), "Animal", 5, 0, 2, 'A', nullptr) {
    // Inicjalizowanie zmiennych domyślnych
    x = 100;        // Domyślna pozycja X
    yn = 200;       // Domyślna pozycja Y
    wcwidth = 50;   // Domyślna szerokość
    height = 100;   // Domyślna wysokość
}
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


std::string Animal::toString() const {
    return species + " at (" + std::to_string(position.getX()) + ", " + std::to_string(position.getY()) + ")";
}


void Animal::collision(Organism* other) {
  
}

void Animal::reproduce(Animal* partner) {
    // Sprawdź, czy partner nie jest nullptr
    if (partner == nullptr) {
        return;  // Jeśli partner jest nullptr, zakończ metodę
    }

    if (world == nullptr) {
        return;  // Jeśli partner jest nullptr, zakończ metodę
    }

    // Sprawdź, czy oba zwierzęta mają wystarczającą moc do rozmnożenia
    if (this->getPower() < this->getPowerToReproduce() || partner->getPower() < partner->getPowerToReproduce()) {
        // Jeśli któryś z partnerów nie spełnia warunku, wywołaj kolizję
        this->collision(partner);  // Wywołanie kolizji
        return;  // Zakończ działanie metody
    }

    // Sprawdź, czy świat istnieje, aby uniknąć błędu segmentacji
    if (!world) {
        return;  // Jeśli world jest nullptr, zakończ metodę
    }

    // Znajdź wolne pole wokół któregoś z rodziców
    std::vector<Position> freePositions = world->getVectorOfFreePositionsAround(this->getPosition());
    if (freePositions.empty()) {
        return;  // Jeśli brak wolnych pozycji, zakończ rozmnażanie
    }

    // Wybierz losową pozycję dla potomka
    Position childPos = freePositions[rand() % freePositions.size()];

    // Stwórz nowego organizmu (potomka) tego samego typu
    Animal* child = this->createOffspring(childPos);
    if (child) {
        world->addOrganism(child);  // Dodaj potomka do świata
    }

    // Osłabienie rodziców po rozmnożeniu
    this->setPower(this->getPower() / 2);  // Pierwszy rodzic
    partner->setPower(partner->getPower() / 2);  // Drugi rodzic
}


void Animal::draw(SDL_Renderer* renderer) {
    // Ustawienie koloru dla zwierzęcia (np. niebieski)
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    // Rysowanie prostokąta reprezentującego zwierzę
    SDL_Rect rect = {this->x, this->yn, this->wcwidth, this->height};  // Teraz działa, ponieważ 'this' odnosi się do instancji klasy
    SDL_RenderFillRect(renderer, &rect);
}
