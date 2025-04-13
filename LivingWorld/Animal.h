// #pragma once
// #include "Organism.h"

// using namespace std;

// class Animal : public Organism
// {
// 	public:
// 		Animal(int power, Position position);
// 		Animal();

// };

//niewirt
// #pragma once
// #include "Organism.h"

// class Animal : public Organism {
// public:
//     Animal(int power, Position position, World* world);
//     Animal();
    
//     void move(int dx, int dy) override;
//     void spread() override;
//     Animal* clone() const override;
//     std::string toString() const override;

// 	protected:
//     Position previousPosition;  // Dodane: zapamiętywanie poprzedniej pozycji

// };


#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
    // Konstruktor z parametrami
    Animal(int power, Position position, World* world);
    
    // Konstruktor domyślny
    Animal();
    
    // Nadpisane metody wirtualne z klasy bazowej
    virtual void move(int dx, int dy) override;
    virtual void spread() override;
    virtual Animal* clone() const override;
    virtual std::string toString() const override;

protected:
    Position previousPosition;  // Zapamiętywanie poprzedniej pozycji
};
