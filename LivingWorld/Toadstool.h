#pragma once
#include "Plant.h"

class Toadstool : public Plant {
public:
    Toadstool(int power, Position position, World* world);
    Toadstool(int power, Position position, std::string species, World* world); // DODANE
    Toadstool();

    void spread() override;
    Toadstool* clone() const override;
    std::string toString() const override;
    void collision(Organism* other) override;
};
