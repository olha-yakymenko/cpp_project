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
#include "Grass.h"
#include <iostream>
#include <cstdlib>


void Sheep::initializeAttributes() {
    setSpecies("Sheep");
    setInitiative(3);
    setLiveLength(10);
    setPowerToReproduce(6);
    setSign('S');
}


Sheep::Sheep(Position position, World* world)
    : Animal(3, position, world) {
    initializeAttributes();
}

Sheep::Sheep(int power, Position position, std::string species, World* world)
    : Animal(power, position, world) {
    initializeAttributes();
}

Sheep::Sheep()
    : Animal(3, Position(0, 0), nullptr) {
    initializeAttributes();
}


Animal* Sheep::clone() const {
    return new Sheep(*this);  // Implementacja w pliku źródłowym
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
        std::cout << "Sheep at " << getPosition().toString() << " eats poisonous mushroom and dies!" << std::endl;
        setLiveLength(0);  // Owca umiera
    } else if (species == "Wolf") {
        std::cout << "Sheep at " << getPosition().toString() << " was eaten by a wolf!" << std::endl;
        setLiveLength(0);  // Owca umiera
    } else if (species == "Dandelion") {
        std::cout << "Sheep at " << getPosition().toString() << " was eaten a dandelion!" << std::endl;
        setLiveLength(getLiveLength()+1);  
    } 
    
}


void Sheep::move(int dx, int dy) {
    if (getLiveLength() <= 0) return;

    // Sprawdzamy otoczenie w poszukiwaniu trawy
    Position currentPos = getPosition();
    std::pair<int, int> bestMove = findBestMove();  // Znajdź najlepszy ruch (w stronę trawy)

    // Jeśli nie ma trawy, poruszamy się losowo
    if (bestMove == std::pair<int, int>{0, 0}) {
        // Losowy ruch (w 4 kierunkach)
        bestMove = {rand() % 3 - 1, rand() % 3 - 1};  // Losowy kierunek: {-1, 0, 1} dla x i y
    }

    Position newPos = currentPos;
    newPos.move(bestMove.first, bestMove.second);  // Ruch do najlepszego pola

    if (world != nullptr) {
        Organism* target = world->getOrganismFromPosition(newPos);
        collision(target);  // Kolizja (np. owca może zjeść trawę, jeśli to będzie możliwe)
        setPosition(newPos);  // Owca przemieszcza się
    } else {
        setPosition(newPos);  // Jeśli nie ma świata, po prostu się przemieszcza
    }
}
std::pair<int, int> Sheep::findBestMove() {
    // Kierunki: góra, prawo, dół, lewo
    std::vector<std::pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    Position current = getPosition();
    std::pair<int, int> bestMove = {0, 0};  // Domyślnie nie ruszaj się
    int bestPriority = 0;

    // Sprawdzamy, czy world jest poprawnie ustawiony
    if (world == nullptr) {
        std::cerr << "Error: world is null!" << std::endl;
        return bestMove;  // Zwracamy domyślny ruch, jeśli world jest null
    }

    for (auto [dx, dy] : directions) {
        Position checkPos = current;
        checkPos.move(dx, dy);
        Organism* target = world->getOrganismFromPosition(checkPos);

        int priority = 0;

        // Jeśli na sprawdzanej pozycji jest trawa, nadamy wyższy priorytet
        if (dynamic_cast<Grass*>(target)) {  
            priority = 2;  // Wysoki priorytet dla trawy
        } 
        // Jeśli nie ma organizmu (puste pole), nadamy średni priorytet
        else if (target == nullptr) {  
            priority = 1;  // Puste pole ma średni priorytet
        }

        // Jeśli znaleziono lepszy priorytet, zapisz ten kierunek jako najlepszy
        if (priority > bestPriority) {
            bestPriority = priority;
            bestMove = {dx, dy};
        }
    }

    return bestMove;
}


Animal* Sheep::createOffspring(Position pos) {
    return new Sheep(pos, world);  // zakładając że masz taki konstruktor
}

// void Sheep::reproduce(Animal* partner) {
//     if (partner == nullptr) {
//         std::cout << "sheep p" << std::endl;
//         return;  // Jeśli partner jest nullptr, zakończ metodę
//     }

//     if (world == nullptr) {
//         std::cout << "sheep" << std::endl;
//         return;  // Jeśli partner jest nullptr, zakończ metodę
//     }
//     // Sprawdź, czy warunki rozmnażania są spełnione
//     if (this->getPower() < this->getPowerToReproduce() || partner->getPower() < partner->getPowerToReproduce()) {
//         // Jeśli nie, wywołaj kolizję
//         this->collision(partner);
//         return;  // Zakończ metodę
//     }

//     // Znajdź wolne pole wokół owcy
//     std::vector<Position> freePositions = world->getVectorOfFreePositionsAround(this->getPosition());
//     if (freePositions.empty()) return;  // Jeśli brak wolnych pozycji, zakończ rozmnażanie

//     // Stwórz potomka w jednej z wolnych pozycji
//     Position childPos = freePositions[rand() % freePositions.size()];
//     Sheep* child = new Sheep(childPos, world);
//     child->setAncestorsHistory(this->getAncestorsHistory());
//     child->addAncestor(this->getBirthTurn(), this->getWorld()->getCurrentTurn());  // Zakładając, że masz odpowiednią metodę konstrukcji dla Sheep
//     world->addOrganism(child);
//     std::cout << "dziecko owcy" << child->getPosition().toString() << std::endl;
//     // Osłabienie rodziców
//     this->setPower(this->getPower() / 2);
//     partner->setPower(partner->getPower() / 2);
// }


Sheep& Sheep::operator=(const Sheep& other) {
    if (this != &other) {  // Sprawdzenie, czy nie przypisujemy do samego siebie
        Animal::operator=(other);  // Kopiowanie danych z klasy bazowej
        ancestorsHistory = other.ancestorsHistory;  // Kopiowanie historii przodków
        setSpecies(other.getSpecies());
        setInitiative(other.getInitiative());
        setLiveLength(other.getLiveLength());
        setPowerToReproduce(other.getPowerToReproduce());
        setSign(other.getSign());
    }
    return *this;
}

// Operator przypisania przenoszącego
Sheep& Sheep::operator=(Sheep&& other) noexcept {
    if (this != &other) {  // Sprawdzenie, czy nie przypisujemy do samego siebie
        Animal::operator=(std::move(other));  // Przenoszenie danych z klasy bazowej
        ancestorsHistory = std::move(other.ancestorsHistory);  // Przenoszenie historii przodków
        setSpecies(std::move(other.getSpecies()));
        setInitiative(other.getInitiative());
        setLiveLength(other.getLiveLength());
        setPowerToReproduce(other.getPowerToReproduce());
        setSign(other.getSign());
    }
    return *this;
}

Sheep::~Sheep() {
    // Jeśli nie masz dynamicznych wskaźników — pusty wystarczy
}

Sheep::Sheep(const Sheep& other)
    : Animal(other) {
    ancestorsHistory = other.ancestorsHistory;
    setSpecies(other.getSpecies());
    setInitiative(other.getInitiative());
    setLiveLength(other.getLiveLength());
    setPowerToReproduce(other.getPowerToReproduce());
    setSign(other.getSign());
}

Sheep::Sheep(Sheep&& other) noexcept
    : Animal(std::move(other)) {
    ancestorsHistory = std::move(other.ancestorsHistory);
    setSpecies(std::move(other.getSpecies()));
    setInitiative(other.getInitiative());
    setLiveLength(other.getLiveLength());
    setPowerToReproduce(other.getPowerToReproduce());
    setSign(other.getSign());
}
