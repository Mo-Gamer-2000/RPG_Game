#pragma once
#include "Header.h"

class Location {
public:
    // Constructor for the Location class
    // This function is called whenever a new Location object is created
    // It initializes the location's name and coordinates to specific values
    Location(string name, int x, int y) : name_(name), x_(x), y_(y) {}

    // Accessor functions to retrieve the name and coordinates of the location
    string getName() const { return name_; }
    int getX() const { return x_; }
    int getY() const { return y_; }

    // Mutator functions to change the name and coordinates of the location
    void setName(string name) { name_ = name; }
    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y; }

private:
    // Member variables to store the name and coordinates of the location
    string name_;
    int x_;
    int y_;
};
