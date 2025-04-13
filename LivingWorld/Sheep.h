// #pragma once
// #include "Animal.h"

// class Sheep : public Animal {
// public:
//     Sheep(Position position, World* world);
//     Sheep();

//     Animal* clone() const override;

//     std::string toString() const override;
// };


#pragma once
#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep(Position position, World* world);
    Sheep(int power, Position position, std::string species, World* world); // DODANE
    Sheep();

    Position getPosition() const override {
        return position;  // Jeśli nie zmieniasz logiki, wystarczy przekazać to samo
    }

    Animal* clone() const override;
    std::string toString() const override;
    void move(int dx, int dy) override;
    void collision(Organism* other) override;
};
