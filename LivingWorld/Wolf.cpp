#include "Wolf.h"
#include "World.h"
#include <iostream>
#include "Sheep.h"
#include "Grass.h"

void Wolf::initializeAttributes() {
    setSpecies("Wolf");
    setInitiative(5);
    setLiveLength(20);
    setPowerToReproduce(16);
    setSign('W');
}

Wolf::Wolf(Position position, World* world)
    : Animal(8, position, world) {
    initializeAttributes();
}

Wolf::Wolf(int power, Position position, std::string species, World* world)
    : Animal(power, position, world) {
    initializeAttributes();
}

Wolf::Wolf()
    : Animal(3, Position(0, 0), nullptr) {
    initializeAttributes();
}

void Wolf::initializeAttributes() {
    setSpecies("Wolf");
    setInitiative(5);
    setLiveLength(20);
    setPowerToReproduce(16);
    setSign('W');
}

Animal* Wolf::clone() const {
    Wolf* clonedWolf = new Wolf(*this);
    clonedWolf->setAncestorsHistory(this->getAncestorsHistory()); // Przenosimy historię przodków
    return clonedWolf;
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
    // else if (species == "Wolf") {
    //     // Wilk spotyka innego wilka (można dodać odpowiednią reakcję, np. walka lub ignorowanie)
    //     std::cout << "Wolf at " << getPosition().toString() << " encounters another wolf!" << std::endl;
    //     // Można dodać inne reakcje na spotkanie z innym wilkiem, np. walkę
    // }
    else if (species == "Wolf") {
        // Wilk spotyka innego wilka
        Wolf* otherWolf = dynamic_cast<Wolf*>(other);  // Sprawdzamy, czy drugi organizm to wilk
        if (otherWolf != nullptr) {
            std::cout << "Wolf at " << getPosition().toString() << " encounters another wolf!" << std::endl;

            // Porównujemy siłę obu wilków
            if (this->getPower() > otherWolf->getPower()) {
                std::cout << "Wolf at " << getPosition().toString() << " defeats the other wolf!" << std::endl;
                // Wilk wygrywa, przejmuje pozycję drugiego wilka
                this->setPosition(otherWolf->getPosition());
                otherWolf->setLiveLength(0);  // Przegrany wilk umiera
            } else if (this->getPower() < otherWolf->getPower()) {
                std::cout << "Wolf at " << otherWolf->getPosition().toString() << " defeats the first wolf!" << std::endl;
                // Inny wilk wygrywa, ten przegrał i umiera
                this->setLiveLength(0);  // Przegrany wilk umiera
            } else {
                // Jeżeli siła jest taka sama, obaj wilki umierają
                std::cout << "Wolf at " << getPosition().toString() << " and wolf at " << otherWolf->getPosition().toString() << " are equally strong and both die!" << std::endl;
                this->setLiveLength(0);  // Oba wilki umierają
                otherWolf->setLiveLength(0);  // Drugi wilk również umiera
            }
        }
    } 
    else if (species == "Dandelion") {
        std::cout << "Wolf at " << getPosition().toString() << " was eaten a dandelion!" << std::endl;
        setLiveLength(getLiveLength()+1);  
    } 
    else {
        // W przypadku innych organizmów, wilk nic nie robi
        std::cout << "Wolf at " << getPosition().toString() << " encounters " << species << ", but does nothing." << std::endl;
    }
}

Animal* Wolf::createOffspring(Position pos) {
    return new Wolf(pos, world);  // zakładając że masz taki konstruktor
}


// void Wolf::reproduce(Animal* partner) {
//     if (partner == nullptr) {
//         std::cout << "WILKp" << std::endl;
//         return;  // Jeśli partner jest nullptr, zakończ metodę
//     }

//     if (world == nullptr) {
//         std::cout << "WILK" << std::endl;
//         return;  // Jeśli partner jest nullptr, zakończ metodę
//     }
//     // Sprawdź, czy warunki rozmnażania są spełnione
//     if (this->getPower() < this->getPowerToReproduce() || partner->getPower() < partner->getPowerToReproduce()) {
//         // Jeśli nie, wywołaj kolizję
//         this->collision(partner);
//         return;  // Zakończ metodę
//     }

//     // Znajdź wolne pole wokół wilka
//     std::vector<Position> freePositions = world->getVectorOfFreePositionsAround(this->getPosition());
//     if (freePositions.empty()) return;  // Jeśli brak wolnych pozycji, zakończ rozmnażanie

//     // Stwórz potomka w jednej z wolnych pozycji
//     Position childPos = freePositions[rand() % freePositions.size()];
//     Wolf* child = new Wolf(childPos, world); 
//     child->setAncestorsHistory(this->getAncestorsHistory());
//     child->addAncestor(this->getBirthTurn(), this->getWorld()->getCurrentTurn());
//     world->addOrganism(child);
//     std::cout << "dziecko wilka" << child->getPosition().toString() << std::endl;

//     // Osłabienie rodziców
//     this->setPower(this->getPower() / 2);
//     partner->setPower(partner->getPower() / 2);
// }


void Wolf::reproduce(Animal* partner) {
    if (partner == nullptr) {
        return;  // Jeśli partner jest nullptr, zakończ metodę
    }

    // Sprawdź, czy warunki rozmnażania są spełnione
    if (this->getPower() < this->getPowerToReproduce() || partner->getPower() < partner->getPowerToReproduce()) {
        this->collision(partner);  // Zainicjuj kolizję, jeżeli warunki nie są spełnione
        return;
    }

    // Znajdź wolne pole wokół wilka
    std::vector<Position> freePositions = world->getVectorOfFreePositionsAround(this->getPosition());
    if (freePositions.empty()) return;  // Jeśli brak wolnych pozycji, zakończ rozmnażanie

    // Stwórz potomka w jednej z wolnych pozycji
    Position childPos = freePositions[rand() % freePositions.size()];
    Wolf* child = new Wolf(childPos, world);
    child->setAncestorsHistory(this->getAncestorsHistory());  // Przenosimy historię przodków
    child->addAncestor(this->getBirthTurn(), world->getCurrentTurn());  // Dodajemy przodków z rodzica

    world->addOrganism(child);  // Dodajemy potomka do świata
    std::cout << "Wilk o pozycji " << child->getPosition().toString() << " się narodził!" << std::endl;

    // Osłabienie rodziców po rozmnażaniu
    this->setPower(this->getPower() / 2);
    partner->setPower(partner->getPower() / 2);
}


// Konstruktor kopiujący
Wolf::Wolf(const Wolf& other)
    : Animal(other) {  // Kopiujemy część Animal
    setSpecies(other.getSpecies());
    setInitiative(other.getInitiative());
    setLiveLength(other.getLiveLength());
    setPowerToReproduce(other.getPowerToReproduce());
    setSign(other.getSign());
    setWorld(other.getWorld());
    setPosition(other.getPosition());
    setAncestorsHistory(other.getAncestorsHistory());  // Kopiowanie historii przodków
}

// Konstruktor przenoszący
Wolf::Wolf(Wolf&& other) noexcept
    : Animal(std::move(other)) {  // Przenosimy część Animal
    setSpecies(std::move(other.getSpecies()));
    setInitiative(other.getInitiative());
    setLiveLength(other.getLiveLength());
    setPowerToReproduce(other.getPowerToReproduce());
    setSign(other.getSign());
    setWorld(other.getWorld());
    setPosition(other.getPosition());
    setAncestorsHistory(std::move(other.getAncestorsHistory()));  // Przenosimy historię przodków

    // Po przeniesieniu obiektu, warto wyzerować dane, by inne obiekty nie miały dostępu do tych samych zasobów
    other.setWorld(nullptr);
    other.setPower(0);
    other.setInitiative(0);
    other.setLiveLength(0);
    other.setPowerToReproduce(0);
    other.setSign(' ');
}


Wolf& Wolf::operator=(Wolf&& other) noexcept {
    if (this != &other) {
        Animal::operator=(std::move(other));  // Przenosimy część z Animal
        setAncestorsHistory(std::move(other.getAncestorsHistory()));  // Przenosimy historię przodków
        other.setAncestorsHistory({});  // Zerujemy historię u przenoszonego obiektu
    }
    return *this;
}


Wolf& Wolf::operator=(const Wolf& other) {
    if (this != &other) {
        Animal::operator=(other);  // Kopiujemy część Animal
        setAncestorsHistory(other.getAncestorsHistory());  // Kopiujemy historię przodków
    }
    return *this;
}
