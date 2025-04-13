// #include <iostream>
// #include "Position.h"
// #include "Organism.h"
// #include "Plant.h"
// #include "Animal.h"
// #include "World.h"

// using namespace std;

// int main()
// {
// 	// Position 
// 	Position p1;
// 	Position p2{ 1, 1 };
// 	Position p3{ -3, -5 };

// 	//cout << p1.toString() << endl;
// 	//cout << p2.toString() << endl;
// 	//cout << p3.toString() << endl;
// 	//cout << p1.distance(p2) << endl;
// 	//p2.move(4, 6);
// 	//cout << p2.toString() << endl;

// 	// Organism
// 	//Organism org1;
// 	//Organism org2{ 10, p2 };

// 	//cout << org1.toString() << endl;
// 	//cout << org2.toString() << endl;
// 	//org1.move(2, 3);
// 	//cout << org1.toString() << endl;

// 	// Plant & Animal
// 	Plant plant{ 3, p3 };
// 	Animal animal{ 5, p2 };
// 	Plant plant2;
// 	Animal animal2;

// 	cout << plant.toString() << endl;
// 	cout << animal.toString() << endl;
// 	cout << plant2.toString() << endl;
// 	cout << animal2.toString() << endl;
// 	plant.move(3, 4);
// 	cout << plant.toString() << endl;
// 	animal.move(1, 2);
// 	cout << animal.toString() << endl;
	
// 	// World test
// 	World world;
// 	Position posP1{ 4, 5 };
// 	Plant plantW1{ 3, posP1 };
// 	Position posP2{ 5, 4 };
// 	Plant plantW2{ 3, posP2 };

// 	Position posW2{ 3, 2 };
// 	Animal animalW1{ 6, posW2 };
// 	Position posW3{ 2, 3 };
// 	Animal animalW2{ 6, posW3 };

// 	world.addOrganism(&plantW1);
// 	world.addOrganism(&plantW2);
// 	world.addOrganism(&animalW1);
// 	world.addOrganism(&animalW2);

// 	auto positions = world.getVectorOfFreePositionsAround(Position(5, 5));

// 	for(auto pos: positions)
// 		cout << pos.toString() << endl;

// 	// Tura 0
// 	cout << world.toString() << endl;

// 	// Tura 1
// 	world.makeTurn();
// 	cout << world.toString() << endl;

// 	// Tura 2
// 	world.makeTurn();
// 	cout << world.toString() << endl;

// 	world.writeWorld("world.bin");

// 	// Tura 3
// 	world.makeTurn();
// 	cout << world.toString() << endl;

// 	// powrot do Tury 2
// 	world.readWorld("world.bin");
// 	cout << world.toString() << endl;

// 	return 0;
// }




// #include <iostream>
// #include "Position.h"
// #include "Organism.h"
// #include "Plant.h"
// #include "Grass.h"
// #include "Animal.h"
// #include "World.h"
// #include "Sheep.h"  // Jeżeli będziesz używał Owcy

// using namespace std;

// int main() {
//     // Inicjalizacja świata
//     World world(20, 20);       // Świat o rozmiarze 20x20

//     // Inicjalizacja pozycji
//     Position p1;               // Domyślna pozycja (0, 0)
//     Position p2{1, 1};         // Pozycja 1,1
//     Position p3{-3, -5};       // Pozycja -3,-5

//     // Tworzenie organizmów: rośliny i zwierzęta
//     Plant plant{3, p3, &world};  // Roślina o mocy 3 w pozycji p3, z przekazaniem wskaźnika na świat
//     Animal animal{5, p2, &world};  // Zwierzę o mocy 5 w pozycji p2, z przekazaniem wskaźnika na świat

//     Plant plant2{3, p3, &world};   // Roślina o mocy 3, z przekazaniem wskaźnika na świat
//     Animal animal2{5, p3, &world}; // Zwierzę o mocy 5, z przekazaniem wskaźnika na świat

//     // cout << plant.toString() << endl;
//     // cout << animal.toString() << endl;
//     // cout << plant2.toString() << endl;
//     // cout << animal2.toString() << endl;

//     // Przemieszczanie organizmów
//     plant.move(3, 4);
//     cout << "After move, plant: " << plant.toString() << endl;
//     animal.move(1, 2);
//     cout << "After move, animal: " << animal.toString() << endl;

//     // Testowanie świata
//     Position posP1{4, 5};
//     Grass* plantW1 = new Grass(3, posP1, &world);  // Tworzymy trawę

//     Position posP2{5, 4};
//     Grass* plantW2 = new Grass(3, posP2, &world);  // Tworzymy trawę

//     Position posW2{3, 2};
//     Animal* animalW1 = new Animal(6, posW2, &world);  // Tworzymy zwierzę

//     Position posW3{2, 3};
//     Animal* animalW2 = new Animal(6, posW3, &world);  // Tworzymy zwierzę

//     // Dodawanie organizmów do świata
//     world.addOrganism(plantW1);
//     world.addOrganism(plantW2);
//     world.addOrganism(animalW1);
//     world.addOrganism(animalW2);

//     // Wyświetlanie wolnych pozycji wokół danej pozycji
//     auto positions = world.getVectorOfFreePositionsAround(Position(5, 5));
//     for (auto pos : positions)
//         cout << pos.toString() << endl;

//     // Symulacja tur
//     cout << "Turn 0:\n" << world.toString() << endl;
//     world.makeTurn();  // Tura 1
//     cout << "Turn 1:\n" << world.toString() << endl;
    
//     world.makeTurn();  // Tura 2
//     cout << "Turn 2:\n" << world.toString() << endl;

//     // Zapis i odczyt świata
//     world.writeWorld("world.bin");

//     world.makeTurn();  // Tura 3
//     cout << "Turn 3:\n" << world.toString() << endl;

//     // Powrót do stanu świata z tury 2
//     world.readWorld("world.bin");
//     cout << "After loading world:\n" << world.toString() << endl;

//     return 0;
// }





// #include <iostream>
// #include "Position.h"
// #include "Organism.h"
// #include "Plant.h"
// #include "Animal.h"
// #include "Grass.h"
// #include "Sheep.h"
// #include "World.h"

// using namespace std;

// int main() {
//     // Position 
//     Position p1;
//     Position p2{ 1, 1 };
//     Position p3{ -3, -5 };

//     // Plant & Animal examples
//     Grass grass{ 3, p3, nullptr };
//     Sheep sheep{ p2, nullptr };
//     Grass grass2;
//     Sheep sheep2;

//     cout << grass.toString() << endl;
//     cout << sheep.toString() << endl;
//     cout << grass2.toString() << endl;
//     cout << sheep2.toString() << endl;

//     // Move Plants and Animals
//     grass.move(3, 4);
//     cout << grass.toString() << endl;
//     sheep.move(1, 2);
//     cout << sheep.toString() << endl;

//     // World test
//     World world;

//     // Add some plants and animals to the world
//     Position posP1{ 4, 5 };
//     Grass grassW1{ 3, posP1, &world };
//     Position posP2{ 5, 4 };
//     Grass grassW2{ 3, posP2, &world };

//     Position posW2{ 3, 2 };
//     Sheep sheepW1{ posW2, &world };
//     Position posW3{ 2, 3 };
//     Sheep sheepW2{ posW3, &world };

//     // Add organisms to the world
//     world.addOrganism(&grassW1);
//     world.addOrganism(&grassW2);
//     world.addOrganism(&sheepW1);
//     world.addOrganism(&sheepW2);

//     // Print free positions around a given position
//     auto positions = world.getVectorOfFreePositionsAround(Position(5, 5));
//     for (auto pos : positions)
//         cout << pos.toString() << endl;

//     // Display world state at Turn 0
//     cout << "Turn 0:" << endl;
//     cout << world.toString() << endl;

//     // Make Turn 1
//     world.makeTurn();
//     cout << "Turn 1:" << endl;
//     cout << world.toString() << endl;

//     // Make Turn 2
//     world.makeTurn();
//     cout << "Turn 2:" << endl;
//     cout << world.toString() << endl;

//     // Save the world state to a file
//     world.writeWorld("world.bin");

//     // Make Turn 3
//     world.makeTurn();
//     cout << "Turn 3:" << endl;
//     cout << world.toString() << endl;

//     // Read world state from file and return to Turn 2 state
//     world.readWorld("world.bin");
//     cout << "Back to Turn 2:" << endl;
//     cout << world.toString() << endl;

//     return 0;
// }


//world 01
// #include <iostream>
// #include "Position.h"
// #include "Organism.h"
// #include "Plant.h"
// #include "Animal.h"
// #include "Grass.h"
// #include "Sheep.h"
// #include "World.h"

// using namespace std;

// int main() {
//     // Position examples
//     Position p1;
//     Position p2{ 1, 1 };
//     Position p3{ -3, -5 };

//     // Plant & Animal examples
//     Grass grass{ 3, p3, nullptr };
//     Sheep sheep{ p2, nullptr };
//     Grass grass2;
//     Sheep sheep2;

//     // Print initial states
//     cout << "Initial state:" << endl;
//     cout << grass.toString() << endl;
//     cout << sheep.toString() << endl;
//     cout << grass2.toString() << endl;
//     cout << sheep2.toString() << endl;

//     // Move Plants and Animals
//     grass.move(3, 4);
//     cout << "Moved grass to: " << grass.toString() << endl;
//     sheep.move(1, 2);
//     cout << "Moved sheep to: " << sheep.toString() << endl;

//     // World test
//     World world;

//     // Add some plants and animals to the world
//     Position posP1{ 4, 5 };
//     Grass grassW1{ 3, posP1, &world };
//     Position posP2{ 5, 4 };
//     Grass grassW2{ 3, posP2, &world };

//     Position posW2{ 3, 2 };
//     Sheep sheepW1{ posW2, &world };
//     Position posW3{ 2, 3 };
//     Sheep sheepW2{ posW3, &world };

//     // Add organisms to the world
//     world.addOrganism(&grassW1);
//     world.addOrganism(&grassW2);
//     world.addOrganism(&sheepW1);
//     world.addOrganism(&sheepW2);

//     // Adding more grass to the world
//     // Dodajemy dużo trawy w różnych miejscach
//     for (int i = 0; i < 50; ++i) {
//         Position randomPos{ rand() % 10, rand() % 10 };  // Random positions between (0,0) and (9,9)
//         Grass* newGrass = new Grass{ 3, randomPos, &world };
//         world.addOrganism(newGrass);
//     }

//     // Print free positions around a given position
//     auto positions = world.getVectorOfFreePositionsAround(Position(5, 5));
//     cout << "Free positions around (5,5):" << endl;
//     for (auto pos : positions)
//         cout << pos.toString() << endl;

//     // Display world state at Turn 0
//     cout << "Turn 0:" << endl;
//     cout << world.toString() << endl;

//     // Make Turn 1
//     world.makeTurn();
//     cout << "Turn 1:" << endl;
//     cout << world.toString() << endl;

//     // Make Turn 2
//     world.makeTurn();
//     cout << "Turn 2:" << endl;
//     cout << world.toString() << endl;

//     // Save the world state to a file
//     world.writeWorld("world.bin");

//     // Make Turn 3
//     world.makeTurn();
//     cout << "Turn 3:" << endl;
//     cout << world.toString() << endl;

//     // Read world state from file and return to Turn 2 state
//     world.readWorld("world.bin");
//     cout << "Back to Turn 2:" << endl;
//     cout << world.toString() << endl;

//     return 0;
// }







#include <iostream>
#include "Position.h"
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "Grass.h"
#include "Sheep.h"
#include "Dandelion.h"  // Include Dandelion
#include "Wolf.h"       // Include Wolf
#include "World.h"

using namespace std;

int main() {
    // Position examples
    Position p1;
    Position p2{ 1, 1 };
    Position p3{ -3, -5 };

    // Plant & Animal examples
    Grass grass{ 3, p3, nullptr };
    Sheep sheep{ p2, nullptr };
    Grass grass2;
    Sheep sheep2;

    // Dandelion example
    Position pDandelion{ 2, 2 };
    Dandelion dandelion{ 2, pDandelion, nullptr };

    // Print initial states
    cout << "Initial state:" << endl;
    cout << grass.toString() << endl;
    cout << sheep.toString() << endl;
    cout << grass2.toString() << endl;
    cout << sheep2.toString() << endl;
    cout << dandelion.toString() << endl;

    // Move Plants and Animals
    grass.move(3, 4);
    cout << "Moved grass to: " << grass.toString() << endl;
    sheep.move(1, 2);
    cout << "Moved sheep to: " << sheep.toString() << endl;

    // World test
    World world;

    // Add organisms to the world, including Dandelion
    Position posP1{ 4, 5 };
    Grass grassW1{ 3, posP1, &world };
    Position posP2{ 5, 4 };
    Grass grassW2{ 3, posP2, &world };

    Position posW2{ 3, 2 };
    Sheep sheepW1{ posW2, &world };
    Position posW3{ 2, 3 };
    Sheep sheepW2{ posW3, &world };

    Position posDandelion{ 6, 6 };
    Dandelion dandelionW{ 3, posDandelion, &world };

    // Wolf example
    Position posWolf{ 1, 4 };
    Wolf wolfW{ posWolf, &world };

    // Add organisms to the world
    world.addOrganism(&grassW1);
    world.addOrganism(&grassW2);
    world.addOrganism(&sheepW1);
    world.addOrganism(&sheepW2);
    world.addOrganism(&dandelionW);  // Adding dandelion to world
    world.addOrganism(&wolfW);       // Adding wolf to world

    // Adding more grass to the world
    for (int i = 0; i < 50; ++i) {
        Position randomPos{ rand() % 10, rand() % 10 };  // Random positions between (0,0) and (9,9)
        Grass* newGrass = new Grass{ 3, randomPos, &world };
        world.addOrganism(newGrass);
    }

    // Print free positions around a given position
    auto positions = world.getVectorOfFreePositionsAround(Position(5, 5));
    cout << "Free positions around (5,5):" << endl;
    for (auto pos : positions)
        cout << pos.toString() << endl;

    // Display world state at Turn 0
    cout << "Turn 0:" << endl;
    cout << world.toString() << endl;

    // Make Turn 1
    world.makeTurn();
    cout << "Turn 1:" << endl;
    cout << world.toString() << endl;

    // Make Turn 2
    world.makeTurn();
    cout << "Turn 2:" << endl;
    cout << world.toString() << endl;

    // Save the world state to a file
    world.writeWorld("world.bin");

    // Make Turn 3
    world.makeTurn();
    cout << "Turn 3:" << endl;
    cout << world.toString() << endl;

    // Read world state from file and return to Turn 2 state
    world.readWorld("world.bin");
    cout << "Back to Turn 2:" << endl;
    cout << world.toString() << endl;

    return 0;
}
