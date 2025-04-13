// #pragma once
// #include "Organism.h"

// class Plant : public Organism
// {
// 	public:
// 		Plant(int power, Position position);
// 		Plant();

// 		void move(int dx, int dy);
// };

//niewirt
// #pragma once
// #include "Organism.h"

// class Plant : public Organism {
// public:
//     Plant(int power, Position position, World* world);
//     Plant();

//     void move(int dx, int dy) override;
//     void spread() override;
//     std::string toString() const override;
//     Organism* clone() const override; // Typ zwrotny zmieniony na Organism*

// };


#pragma once
#include "Organism.h"

class Plant : public Organism {
public:
    // Konstruktor z parametrami
    Plant(int power, Position position, World* world);
    
    // Konstruktor domyślny
    Plant();

    // Nadpisane metody wirtualne z klasy bazowej
    virtual void move(int dx, int dy) override;
    virtual void spread() override;
    virtual std::string toString() const override;
    virtual Organism* clone() const override;  // Typ zwrotny zmieniony na Organism*

};
