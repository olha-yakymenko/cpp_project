#include "Wolf.h"
#include "World.h"
#include <iostream>
#include "Sheep.h"
#include "Grass.h"

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


std::pair<int, int> Wolf::findBestMove() {
    // Możliwe kierunki ruchu (góra, prawo, dół, lewo)
    std::vector<std::pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}  // góra, prawo, dół, lewo
    };

    Position current = getPosition();
    std::pair<int, int> bestMove = {0, 0};  // domyślnie nie ruszaj się
    int bestPriority = -1;

    // Sprawdzamy otoczenie wilka
    for (auto [dx, dy] : directions) {
        Position checkPos = current;
        checkPos.move(dx, dy);
        Organism* target = world->getOrganismFromPosition(checkPos);

        int priority = 0;
        
        // Jeśli znajdziemy owcę
        if (dynamic_cast<Sheep*>(target)) {
            priority = 3;  // Najwyższy priorytet
        } 
        // Jeśli znajdziemy trawę
        else if (dynamic_cast<Grass*>(target)) {
            priority = 2;
        }
        // Jeśli pole jest wolne
        else if (target == nullptr) {
            priority = 1;
        }

        // Jeśli mamy wyższy priorytet, zmieniamy najlepszy ruch
        if (priority > bestPriority) {
            bestPriority = priority;
            bestMove = {dx, dy};
        }
    }

    // Jeśli najlepszy ruch jest do owcy, wilk będzie się starał w jej stronę
    return bestMove;
}



void Wolf::move(int dx_unused, int dy_unused) {
    if (getLiveLength() <= 0) return;

    auto [dx, dy] = findBestMove();

    Position newPos = getPosition();
    newPos.move(dx, dy);

    if (world != nullptr) {
        Organism* organismAtNewPos = world->getOrganismFromPosition(newPos);

        if (organismAtNewPos != nullptr) {
            this->collision(organismAtNewPos);
        } else {
            setPosition(newPos);
        }
    }
}



void Wolf::collision(Organism* other) {
    if (other == nullptr) return;

    std::string species = other->getSpecies();

    if (species == "Sheep") {
        // Wilk zjada owcę
        std::cout << "Wolf at " << getPosition().toString() << " eats sheep at " << other->getPosition().toString() << "!" << std::endl;
        setPower(getPower() + other->getPower());  // Wilk zwiększa swoją moc
        setPosition(other->getPosition());  // Wilk przejmuje pozycję owcy
    } 

    else if (species == "Toadstool") {
        // Wilk je trujące grzyby (jeśli tak założyliśmy w mechanice)
        std::cout << "Wolf at " << getPosition().toString() << " eats poisonous mushroom and dies!" << other->getPosition().toString() << std::endl;
        setLiveLength(0);  // Wilk umiera po zjedzeniu trującego grzyba
    } 
    else if (species == "Wolf") {
        // Wilk spotyka innego wilka (można dodać odpowiednią reakcję, np. walka lub ignorowanie)
        std::cout << "Wolf at " << getPosition().toString() << " encounters another wolf!" << std::endl;
        // Można dodać inne reakcje na spotkanie z innym wilkiem, np. walkę
    }
    else {
        // W przypadku innych organizmów, wilk nic nie robi
        std::cout << "Wolf at " << getPosition().toString() << " encounters " << species << ", but does nothing." << std::endl;
    }
}

Animal* Wolf::createOffspring(Position pos) {
    return new Wolf(pos, world);  // zakładając że masz taki konstruktor
}


void Wolf::reproduce(Animal* partner) {
    if (partner == nullptr) {
        std::cout << "WILKp" << std::endl;
        return;  // Jeśli partner jest nullptr, zakończ metodę
    }

    if (world == nullptr) {
        std::cout << "WILK" << std::endl;
        return;  // Jeśli partner jest nullptr, zakończ metodę
    }
    // Sprawdź, czy warunki rozmnażania są spełnione
    if (this->getPower() < this->getPowerToReproduce() || partner->getPower() < partner->getPowerToReproduce()) {
        // Jeśli nie, wywołaj kolizję
        this->collision(partner);
        return;  // Zakończ metodę
    }

    // Znajdź wolne pole wokół wilka
    std::vector<Position> freePositions = world->getVectorOfFreePositionsAround(this->getPosition());
    if (freePositions.empty()) return;  // Jeśli brak wolnych pozycji, zakończ rozmnażanie

    // Stwórz potomka w jednej z wolnych pozycji
    Position childPos = freePositions[rand() % freePositions.size()];
    Wolf* child = new Wolf(childPos, world);  // Zakładając, że masz odpowiednią metodę konstrukcji dla Wolf
    world->addOrganism(child);
    std::cout << "dziecko wilka" << child->getPosition().toString() << std::endl;

    // Osłabienie rodziców
    this->setPower(this->getPower() / 2);
    partner->setPower(partner->getPower() / 2);
}