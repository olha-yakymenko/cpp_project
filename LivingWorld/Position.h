// #pragma once
// #include <string>  // Zawiera definicję typu std::string
// #include <iostream>
// using namespace std;  // Może być, ale zazwyczaj lepiej unikać w pliku nagłówkowym

// class Position {
// private:
//     int x;
//     int y;

// public:
//     Position(int x, int y);
//     Position() : x(0), y(0) {}

//     int getX() const;  
//     void setX(int x);
//     int getY() const;
//     void setY(int y);

//     std::string toString() const;  // Teraz 'string' będzie rozpoznawane

//     double distance(Position position);
//     void move(int dx, int dy);

//     bool operator==(const Position& other) const;

//     bool isValid() const;
// };



#pragma once
#include <string>

class Position {
private:
    int x;
    int y;

public:
    Position(int x = 0, int y = 0);

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);

    void move(int dx, int dy);
    bool isValid() const;

    double distance(Position position) const;
    std::string toString() const;
	bool operator==(const Position& other) const {
		return x == other.x && y == other.y;
	}
	
};
