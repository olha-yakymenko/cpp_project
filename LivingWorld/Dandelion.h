#pragma once
#include "Plant.h"

class Dandelion : public Plant {
public:
    Dandelion(int power, Position position, World* world);
    Dandelion(int power, Position position, std::string species, World* world); // DODANE
    Dandelion();

    void spread() override;
    Dandelion* clone() const override;
    std::string toString() const override;
    void collision(Organism* other) override;
    private:
    void initializeDandelion();

};
