#pragma once
#include "Header.h"

// Class definition for the Game class
class startGame
{
public:
    // Member function that displays some text and waits for the user to press
    // Enter
    void start()
    {

        // Print a message asking the user to press Enter
        std::cout << "Press Enter to Start the Game" << std::endl;

        // Wait for the user to press Enter
        std::cin.get();

        // Print a message indicating that the game has started
        std::cout << "Starting the Game!" << std::endl;
    }
};