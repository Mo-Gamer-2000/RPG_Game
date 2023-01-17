#pragma once
#include "HUD.h"

class HUD
{
public:
    // Constructor to initialize Name, Gender and Type.
    HUD(std::string name, std::string gender, std::string type) : name_(name), gender_(gender), type_(type) {}

    // Accessor functions to retrieve the Name, Gender and Type.
    std::string getName() const { return name_; }
    std::string getGender() const { return gender_; }
    std::string getType() const { return type_; }

private:
    // Member variables to store the Name, Gender and Type.
    std::string name_;
    std::string gender_;
    std::string type_;
};