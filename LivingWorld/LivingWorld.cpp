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




//do 3d

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include "Position.h"
// #include "Organism.h"
// #include "Plant.h"
// #include "Animal.h"
// #include "Grass.h"
// #include "Sheep.h"
// #include "Dandelion.h"
// #include "Wolf.h"
// #include "World.h"
// #include "Toadstool.h"

// using namespace std;

// int main() {
//     srand(time(0));  // Inicjalizacja generatora losowego

//     // Position examples
//     Position p1;
//     Position p2{ 1, 1 };
//     Position p3{ -3, -5 };

//     // Plant & Animal examples
//     Grass grass{ 3, p3, nullptr };
//     Sheep sheep{ p2, nullptr };
//     Grass grass2;
//     Sheep sheep2;

//     // Dandelion example
//     Position pDandelion{ 2, 2 };
//     Dandelion dandelion{ 2, pDandelion, nullptr };
//     Toadstool toadstool {3, 5, nullptr};
    

//     // Print initial states
//     cout << "Initial state:" << endl;
//     cout << grass.toString() << endl;
//     cout << sheep.toString() << endl;
//     cout << grass2.toString() << endl;
//     cout << sheep2.toString() << endl;
//     cout << dandelion.toString() << endl;
//     cout << toadstool.toString() << endl;

//     // Move Plants and Animals
//     grass.move(3, 4);
//     cout << "Moved grass to: " << grass.toString() << endl;
//     sheep.move(1, 2);
//     cout << "Moved sheep to: " << sheep.toString() << endl;

//     // World test
//     World world;

//     // Add organisms to the world, including Dandelion
//     Position posP1{ 4, 5 };
//     Grass grassW1{ 3, posP1, &world };
//     Position posP2{ 5, 4 };
//     Grass grassW2{ 3, posP2, &world };

//     Position posW2{ 3, 2 };
//     Sheep sheepW1{ posW2, &world };
//     Position posW3{ 2, 3 };
//     Sheep sheepW2{ posW3, &world };

//     Position posDandelion{ 6, 6 };
//     Dandelion dandelionW{ 3, posDandelion, &world };

//     // Wolf example
//     Position posWolf{ 1, 4 };
//     Wolf wolfW{ posWolf, &world };

//     // Add organisms to the world
//     world.addOrganism(&grassW1);
//     world.addOrganism(&grassW2);
//     world.addOrganism(&sheepW1);
//     world.addOrganism(&sheepW2);
//     world.addOrganism(&dandelionW);
//     world.addOrganism(&wolfW);
//     world.addOrganism(&toadstool);

//     // Dodaj dodatkowe wilki
//     for (int i = 0; i < 5; ++i) {
//         Position randomWolfPos{ rand() % 10, rand() % 10 };
//         Wolf* newWolf = new Wolf{ randomWolfPos, &world };
//         world.addOrganism(newWolf);
//     }

//     // Dodaj dodatkowe owce
//     for (int i = 0; i < 10; ++i) {
//         Position randomSheepPos{ rand() % 10, rand() % 10 };
//         Sheep* newSheep = new Sheep{ randomSheepPos, &world };
//         world.addOrganism(newSheep);
//     }

//     // Adding more grass to the world
//     for (int i = 0; i < 50; ++i) {
//         Position randomPos{ rand() % 10, rand() % 10 };
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

//     // Turn 1
//     world.makeTurn();
//     cout << "Turn 1:" << endl;
//     cout << world.toString() << endl;

//     // Turn 2
//     world.makeTurn();
//     cout << "Turn 2:" << endl;
//     cout << world.toString() << endl;

//     // Save the world state to a file
//     world.writeWorld("world.bin");

//     // Turn 3
//     world.makeTurn();
//     cout << "Turn 3:" << endl;
//     cout << world.toString() << endl;

//     // Load previous world state
//     world.readWorld("world.bin");
//     cout << "Back to Turn 2:" << endl;
//     cout << world.toString() << endl;

//     return 0;
// }



// #include <SDL2/SDL.h>
// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include "Position.h"
// #include "Organism.h"
// #include "Plant.h"
// #include "Animal.h"
// #include "Grass.h"
// #include "Sheep.h"
// #include "Dandelion.h"
// #include "Wolf.h"
// #include "World.h"
// #include "Toadstool.h"

// using namespace std;

// // Funkcja do inicjalizacji SDL2
// bool init(SDL_Window*& window, SDL_Renderer*& renderer) {
//     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//         cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
//         return false;
//     }
    
//     // Tworzenie okna
//     window = SDL_CreateWindow("World Simulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
//     if (!window) {
//         cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
//         return false;
//     }
    
//     // Tworzenie renderer'a
//     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     if (!renderer) {
//         cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
//         return false;
//     }

//     return true;
// }

// // Funkcja do czyszczenia zasobów
// void close(SDL_Window* window, SDL_Renderer* renderer) {
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();
// }




// int main() {
//     srand(time(0));  // Inicjalizacja generatora losowego

//     SDL_Window* window = nullptr;
//     SDL_Renderer* renderer = nullptr;

//     // Inicjalizuj SDL2
//     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//         cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
//         return -1;
//     }

//     // Utwórz okno
//     window = SDL_CreateWindow("World Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
//     if (!window) {
//         cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
//         SDL_Quit();
//         return -1;
//     }

//     // Utwórz renderer
//     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     if (!renderer) {
//         cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//         return -1;
//     }

//     // Utwórz świat i organizmy
//     World world;

//     // Przykładowe dodanie organizmów do świata
//     Position pos1{ 4, 5 };
//     Grass grass{ 3, pos1, &world };
//     world.addOrganism(&grass);

//     // Dodanie innych organizmów
//     Position posSheep{ 5, 5 };
//     Sheep sheep{ posSheep, &world };
//     world.addOrganism(&sheep);

//     Position posWolf{ 6, 6 };
//     Wolf wolf{ posWolf, &world };
//     world.addOrganism(&wolf);

//     Position posDandelion{ 7, 7 };
//     Dandelion dandelion{ 2, posDandelion, &world };
//     // world.addOrganism(&dandelion);

//     // Ustawienia renderowania
//     bool quit = false;
//     SDL_Event e;

//     // Liczba tur do wykonania w każdej iteracji
//     int turnsPerFrame = 5;  // Liczba tur do wykonania na raz

//     // Pętla główna aplikacji
//     while (!quit) {
//         // Obsługuje zdarzenia
//         while (SDL_PollEvent(&e) != 0) {
//             if (e.type == SDL_QUIT) {
//                 quit = true;
//             }
//         }

//         // Wyczyść ekran
//         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Biały kolor tła
//         SDL_RenderClear(renderer);

//         // Wykonaj kilka tur gry
//         for (int i = 0; i < turnsPerFrame; ++i) {
//             world.makeTurn(renderer);  // Wykonaj turę, przekazując renderer
//         }

//         // Rysowanie organizmów
//         for (Organism* org : world.getOrganisms()) {
//             if (org->getLiveLength() > 0) {
//                 Position pos = org->getPosition();
//                 SDL_Rect rect = { pos.getX() * 10, pos.getY() * 10, 10, 10 };

//                 if (dynamic_cast<Grass*>(org)) {
//                     SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Zielony kolor dla trawy
//                 }
//                 else if (dynamic_cast<Sheep*>(org)) {
//                     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Biały kolor dla owcy
//                 }
//                 else if (dynamic_cast<Wolf*>(org)) {
//                     SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Czerwony kolor dla wilka
//                 }
//                 // else if (dynamic_cast<Dandelion*>(org)) {
//                 //     SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);  // Żółty kolor dla mlecza
//                 // }

//                 SDL_RenderFillRect(renderer, &rect);
//             }
//         }

//         // Aktualizuj ekran
//         SDL_RenderPresent(renderer);

//         // Dodaj opóźnienie, aby gra nie działała za szybko
//         SDL_Delay(100);
//     }

//     // Zamyka aplikację
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();

//     return 0;
// }




#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Position.h"
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "Grass.h"
#include "Sheep.h"
#include "Dandelion.h"
#include "Wolf.h"
#include "World.h"
#include "Toadstool.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int CELL_SIZE = 15;
const int GRID_WIDTH = SCREEN_WIDTH / CELL_SIZE;
const int GRID_HEIGHT = SCREEN_HEIGHT / CELL_SIZE;
const int MAX_TURNS = 5;

// Funkcja do inicjalizacji SDL2
bool init(SDL_Window*& window, SDL_Renderer*& renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }
    
    window = SDL_CreateWindow("World Simulator", SDL_WINDOWPOS_UNDEFINED, 
                             SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 
                             SDL_WINDOW_SHOWN);
    if (!window) {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

// Funkcja do czyszczenia zasobów
void close(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Funkcja do losowego generowania pozycji
Position getRandomPosition() {
    return {rand() % GRID_WIDTH, rand() % GRID_HEIGHT};
}

// Funkcja do dodawania organizmów do świata
void populateWorld(World& world) {
    // Dodaj trawy
    for (int i = 0; i < 30; ++i) {
        Grass* grass = new Grass(5, getRandomPosition(), &world);
        world.addOrganism(grass);
    }
    
    // Dodaj owce
    for (int i = 0; i < 15; ++i) {
        Sheep* sheep = new Sheep(getRandomPosition(), &world);
        world.addOrganism(sheep);
    }
    
    // Dodaj wilki
    for (int i = 0; i < 5; ++i) {
        Wolf* wolf = new Wolf(getRandomPosition(), &world);
        world.addOrganism(wolf);
    }
    
    // Dodaj mlecze
    for (int i = 0; i < 10; ++i) {
        Dandelion* dandelion = new Dandelion(3, getRandomPosition(), &world);
        world.addOrganism(dandelion);
    }
    
    // Dodaj muchomory
    for (int i = 0; i < 5; ++i) {
        Toadstool* toadstool = new Toadstool(4, getRandomPosition(), &world);
        world.addOrganism(toadstool);
    }
}

// Funkcja do renderowania organizmów
void renderOrganisms(SDL_Renderer* renderer, World& world) {
    for (Organism* org : world.getOrganisms()) {
        if (org->getLiveLength() > 0) {
            Position pos = org->getPosition();
            SDL_Rect rect = {pos.getX() * CELL_SIZE, pos.getY() * CELL_SIZE, CELL_SIZE, CELL_SIZE};
            
            if (dynamic_cast<Grass*>(org)) {
                SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255);  // Zielony dla trawy
            }
            else if (dynamic_cast<Sheep*>(org)) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Biały dla owcy
            }
            else if (dynamic_cast<Wolf*>(org)) {
                SDL_SetRenderDrawColor(renderer, 139, 0, 0, 255);  // Ciemnoczerwony dla wilka
            }
            else if (dynamic_cast<Dandelion*>(org)) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);  // Żółty dla mlecza
            }
            else if (dynamic_cast<Toadstool*>(org)) {
                SDL_SetRenderDrawColor(renderer, 160, 32, 240, 255);  // Fioletowy dla muchomora
            }
            
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);  // Ciemna obwódka
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
}


int main() {
    srand(time(0));  // Inicjalizacja generatora losowego

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (!init(window, renderer)) {
        close(window, renderer);
        return -1;
    }

    World world;
    populateWorld(world);
    
    bool quit = false;
    SDL_Event e;
    int turnCount = 0;

    // Główna pętla gry
    while (!quit && turnCount < MAX_TURNS) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Czyszczenie ekranu
        SDL_SetRenderDrawColor(renderer, 240, 240, 240, 255);
        SDL_RenderClear(renderer);

        // Wykonanie tur
        for (int i = 0; i < MAX_TURNS; ++i) {
            if (turnCount >= MAX_TURNS) {
                quit = true;
                break;
            }

            world.makeTurn(renderer);  // przekazujemy renderer
            turnCount++;
            cout << "Turn: " << turnCount << " Organisms: " << world.getOrganisms().size() << endl;
        }

        if (quit) break;

        // Renderowanie
        renderOrganisms(renderer, world);
        SDL_RenderPresent(renderer);

        SDL_Delay(200);  // Opóźnienie dla lepszej widoczności zmian
    }

    close(window, renderer);
    return 0;
}