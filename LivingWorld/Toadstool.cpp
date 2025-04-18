
#include "Toadstool.h"
#include "World.h"
#include <iostream>

Toadstool::Toadstool(int power, Position position, World* world)
    : Plant(0, position, world) {
        setSpecies("Toadstool");
        setInitiative(0);
        setLiveLength(12);
        setPowerToReproduce(4);
        setSign('T');
}

Toadstool::Toadstool(int power, Position position, std::string species, World* world)
    : Plant(0, position, world) {
        setSpecies("Toadstool");
        setInitiative(0);
        setLiveLength(12);
        setPowerToReproduce(4);
        setSign('T');
}

Toadstool::Toadstool()
    : Plant(0, Position(0, 0), nullptr) {
        setSpecies("Toadstool");
        setInitiative(0);
        setLiveLength(12);
        setPowerToReproduce(4);
        setSign('T');
}

void Toadstool::spread() {
    if (getLiveLength() <= 0) return;

    // Ustal, czy grzyb może się rozmnożyć, korzystając z metody getPowerToReproduce
    int powerToReproduce = this->getPowerToReproduce();  // Odczytanie granicy siły potrzebnej do rozmnożenia

    // Jeśli siła organizmu jest większa lub równa niż wymagane minimum, może się rozmnożyć
    if (getPower() >= powerToReproduce) {
        if (getWorld() == nullptr) {
            std::cerr << "Toadstool: World is not initialized!" << std::endl;
            return;
        }

        // Lista możliwych pozycji, na które grzyb może się rozprzestrzenić
        std::vector<Position> adjacentPositions = {
            Position(getPosition().getX() - 1, getPosition().getY()), // Lewa
            Position(getPosition().getX() + 1, getPosition().getY()), // Prawa
            Position(getPosition().getX(), getPosition().getY() - 1), // Górna
            Position(getPosition().getX(), getPosition().getY() + 1)  // Dolna
        };

        // Szukamy pierwszej wolnej komórki wśród sąsiednich pozycji
        for (auto& adjacentPos : adjacentPositions) {
            // Sprawdź, czy sąsiednia pozycja jest w obrębie planszy
            if (adjacentPos.isValid()) {
                // Sprawdź, czy na tej pozycji nie ma innego organizmu
                Organism* organismAtPos = getWorld()->getOrganismFromPosition(adjacentPos);

                if (organismAtPos == nullptr) {
                    // Jeśli pozycja jest wolna, rozprzestrzenić grzyba
                    getWorld()->addOrganism(new Toadstool(3, adjacentPos, getWorld()));
                    std::cout << "Toadstool spread to position: " << adjacentPos.toString() << std::endl;

                    // Po rozmnożeniu grzyb traci połowę swojej siły
                    this->setPower(this->getPower() / 2);  // Traci połowę siły

                    break;  // Tylko jeden grzyb rozprzestrzenia się w tej turze
                }
            }
        }
    }
}


Toadstool* Toadstool::clone() const {
    return new Toadstool(*this);
}

std::string Toadstool::toString() const {
    return "Toadstool at " + getPosition().toString();
}

void Toadstool::collision(Organism* attacker) {
    if (getLiveLength() <= 0) return;

    std::string species = attacker->getSpecies();
    if (species == "Grass" or species=="Dandelion" or species=="Toadstool") {
        
    } else{
    std::cout << attacker->toString() << " at position " << attacker->getPosition().toString()
              << " ate a Toadstool!" << this->getPosition().toString() << std::endl;
    this->setLiveLength(0); 
    } // Muchomor umiera po zjedzeniu
}
// Sheep at (5, 1) at position (5, 1) ate a Toadstool!(5, 0)