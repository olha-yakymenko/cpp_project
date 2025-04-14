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
#include <SDL2/SDL.h>

class Animal : public Organism {
    private:
    int x, yn, wcwidth, height; 
public:
    // Konstruktor z parametrami
    Animal(int power, Position position, World* world);
    
    // Konstruktor domyślny
    Animal();
    
    // Nadpisane metody wirtualne z klasy bazowej
    virtual void move(int dx, int dy) override;
    virtual void spread() override;
    virtual std::string toString() const override;
    void collision(Organism* other) override;
    virtual Animal* createOffspring(Position pos) = 0;
    virtual Animal* clone() const = 0;
    // virtual ~Animal() = default;
    virtual std::pair<int, int> findBestMove() = 0;
    virtual void reproduce(Animal* partner) = 0;

    void draw(SDL_Renderer* renderer) override;
protected:
    Position previousPosition;  // Zapamiętywanie poprzedniej pozycji
};
