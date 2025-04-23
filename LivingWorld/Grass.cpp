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
#include "Sheep.h"
#include "Wolf.h"
#include "Plant.h"

Grass::Grass(int power, Position position, World* world)
    : Plant(power, position, world) {
        initializeAttributes();
}

Grass::Grass(int power, Position position, std::string species, World* world)
    : Plant(power, position, world) {
        initializeAttributes();
}

Grass::Grass()
    : Plant(3, Position(0, 0), nullptr) {
        initializeAttributes();
}

void Grass::initializeAttributes() {
    setSpecies("Grass");
    setInitiative(0);
    setLiveLength(3);
    setPowerToReproduce(3);
    setSign('G');
}

// void Grass::spread() {
//     if (getLiveLength() <= 0) return;

//     if (getWorld() == nullptr) {
//         std::cerr << "Grass: World is not initialized!" << std::endl;
//         return;
//     }

//     // Lista możliwych pozycji, na które trawa może się rozprzestrzenić
//     std::vector<Position> adjacentPositions = {
//         Position(getPosition().getX() - 1, getPosition().getY()), // Lewa
//         Position(getPosition().getX() + 1, getPosition().getY()), // Prawa
//         Position(getPosition().getX(), getPosition().getY() - 1), // Górna
//         Position(getPosition().getX(), getPosition().getY() + 1)  // Dolna
//     };

//     // Iteracja po sąsiednich pozycjach
//     for (auto& adjacentPos : adjacentPositions) {
//         // Sprawdź, czy sąsiednia pozycja jest w obrębie planszy
//         if (adjacentPos.isValid()) {
//             // Sprawdź, czy na tej pozycji nie ma organizmu
//             Organism* organismAtPos = getWorld()->getOrganismFromPosition(adjacentPos);

//             if (organismAtPos == nullptr || dynamic_cast<Plant*>(organismAtPos)) {
//                 // Jeśli pozycja jest wolna lub zajmowana przez inną roślinę, rozprzestrzenić trawę
//                 if (organismAtPos == nullptr) {
//                     getWorld()->addOrganism(new Grass(3, adjacentPos, getWorld()));
//                     std::cout << "Grass spread to position: " << adjacentPos.toString() << std::endl;
//                     setPower(getPower() / 2);
//                 } else {
//                     std::cout << "Grass tried to spread to position: " << adjacentPos.toString() << ", but it's already occupied by a plant." << std::endl;
//                 }
                
//                 break;  // Tylko jedna trawa rozprzestrzenia się w tej turze
//             }
//         }
//     }
// }


void Grass::spread() {
    if (getLiveLength() <= 0) return;

    if (getWorld() == nullptr) {
        std::cerr << "Grass: World is not initialized!" << std::endl;
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
            // Sprawdź, czy na tej pozycji nie ma organizmu lub jest roślina (same rośliny mogą się rozprzestrzeniać)
            Organism* organismAtPos = getWorld()->getOrganismFromPosition(adjacentPos);

            if (organismAtPos == nullptr || dynamic_cast<Plant*>(organismAtPos)) {
                // Jeśli pozycja jest wolna lub zajmowana przez inną roślinę, rozprzestrzenić trawę
                if (organismAtPos == nullptr) {
                    // Tworzymy nową trawę na wolnej pozycji
                    Grass* newGrass = new Grass(3, adjacentPos, getWorld());
                    newGrass->setBirthTurn(getWorld()->getCurrentTurn());  // Ustawienie tury narodzin
                    getWorld()->addOrganism(newGrass);
                    std::cout << "Grass spread to position: " << adjacentPos.toString() << std::endl;
                    setPower(getPower() / 2);  // Zmniejsz moc matki
                } else {
                    std::cout << "Grass tried to spread to position: " << adjacentPos.toString() << ", but it's already occupied by another plant." << std::endl;
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

    // Jeśli kolizja z rośliną, nie robić nic
    if (dynamic_cast<Plant*>(other) or dynamic_cast<Wolf*>(other)) {
        std::cout << "Grass collided with another plant, nothing happened." << std::endl;
        return;
    }

    // Jeśli kolizja z organizmem zwierzęcym, Grass ginie
    if (dynamic_cast<Sheep*>(other)) {
        this->setLiveLength(0);
        std::cout << "Grass was eaten by an animal." << std::endl;
    }
}


Grass::Grass(const Grass& other)
    : Plant(other) {
    setSpecies(other.getSpecies());
    setInitiative(other.getInitiative());
    setLiveLength(other.getLiveLength());
    setPowerToReproduce(other.getPowerToReproduce());
    setSign(other.getSign());
}

Grass::Grass(Grass&& other) noexcept
    : Plant(std::move(other)) {
    setSpecies(std::move(other.getSpecies()));
    setInitiative(other.getInitiative());
    setLiveLength(other.getLiveLength());
    setPowerToReproduce(other.getPowerToReproduce());
    setSign(other.getSign());
}

Grass& Grass::operator=(const Grass& other) { //operator przypisania kopiujacy
    if (this != &other) {
        Plant::operator=(other);
        setSpecies(other.getSpecies());
        setInitiative(other.getInitiative());
        setLiveLength(other.getLiveLength());
        setPowerToReproduce(other.getPowerToReproduce());
        setSign(other.getSign());
    }
    return *this;
}

Grass& Grass::operator=(Grass&& other) noexcept { //operator przypisania przenoszacy
    if (this != &other) {
        Plant::operator=(std::move(other));
        setSpecies(std::move(other.getSpecies()));
        setInitiative(other.getInitiative());
        setLiveLength(other.getLiveLength());
        setPowerToReproduce(other.getPowerToReproduce());
        setSign(other.getSign());
    }
    return *this;
}

Grass::~Grass() {
    // Jeżeli kiedyś dodasz coś dynamicznego – obsłuż tutaj
}
