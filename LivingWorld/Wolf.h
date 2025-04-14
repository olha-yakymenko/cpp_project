
#pragma once
#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf(Position position, World* world);
    Wolf(int power, Position position, std::string species, World* world); // DODANE
    Wolf();

    Position getPosition() const override {
        return position;  // Jeśli nie zmieniasz logiki, wystarczy przekazać to samo
    }

    Animal* clone() const override;
    std::string toString() const override;
    void move(int dx, int dy) override;
    void collision(Organism* other) override;
    Animal* createOffspring(Position pos) override;
    std::pair<int, int> findBestMove() override;
    void reproduce(Animal* partner) override;
};