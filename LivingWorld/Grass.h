// #pragma once
// #include "Plant.h"

// class Grass : public Plant {
// public:
//     Grass(int power, Position position, World* world);
//     Grass();
    
//     void spread() override;
//     Grass* clone() const override;
//     std::string toString() const override;
// };


#pragma once
#include "Plant.h"

class Grass : public Plant {
public:
    Grass(int power, Position position, World* world);
    Grass(int power, Position position, std::string species, World* world); // DODANE
    Grass();

    void spread() override;
    Grass* clone() const override;
    std::string toString() const override;
    void collision(Organism* other) override;
};
