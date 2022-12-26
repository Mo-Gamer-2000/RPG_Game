#include "Player.h"  // Include the header file for the Player class

// Class definition for the Game class
class Game {
public:

    // Member function that displays some text and waits for the user to press Enter
    void start() {

        // Print a message asking the user to press Enter
        std::cout << "Press Enter to Start the Game" << std::endl;

        // Wait for the user to press Enter
        std::cin.get();

        // Print a message indicating that the game has started
        std::cout << "Starting the Game!" << std::endl;
    }
};

class Intro {
public:

    // Display Function has a Loading Screen and Displays Text.
    void display() {

        // Display the Loading Animation.
        for (int i = 0; i < 100; i++) {
            // Print the current loading percentage to the console.
            std::cout << "Loading: " << i << "%" << std::endl;

            // Pause for 1000 milliseconds divided by the frame rate.
            std::this_thread::sleep_for(std::chrono::milliseconds(1000 / kFrameRate_));

            // Clear the console.
            system("cls");
        }

        // Display the Text "WELCOME TO MY GAME".
        std::cout << " ____ " << std::endl;
        std::cout << "|    |" << std::endl;
        std::cout << "| W  |" << std::endl;
        std::cout << "| E  |" << std::endl;
        std::cout << "| L  |" << std::endl;
        std::cout << "| C  |" << std::endl;
        std::cout << "| O  |" << std::endl;
        std::cout << "| M  |" << std::endl;
        std::cout << "| E  |" << std::endl;
        std::cout << "|    |" << std::endl;
        std::cout << "| T  |" << std::endl;
        std::cout << "| O  |" << std::endl;
        std::cout << "|    |" << std::endl;
        std::cout << "| M  |" << std::endl;
        std::cout << "| Y  |" << std::endl;
        std::cout << "|    |" << std::endl;
        std::cout << "| G  |" << std::endl;
        std::cout << "| A  |" << std::endl;
        std::cout << "| M  |" << std::endl;
        std::cout << "| E  |" << std::endl;
        std::cout << "|____|" << std::endl;
    }

private:
    // Number of FPS (frames per second).
    const int kFrameRate_ = 30;
};

class HUD {

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

int main() {
    // Run class game.
    Game game;
    game.start();

    // Run class display.
    Intro intro;
    intro.display();

    // Counter created for creating character For loop.
    int counter = 0;

    // Built Animation to build character.
    std::string name;
    std::string gender;
    std::string type;

    // Prompt the user to enter the name, gender, and type of their character.
    std::cout << "--------------------------" << std::endl;
    std::cout << "|  BUILD YOUR CHARACTER  |" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Enter Name of your Character: ";
    std::cin >> name;
    std::cout << "Enter Gender of your Character (Male/Female): ";
    std::cin >> gender;
    std::cout << "Enter Type of your Character (Warrior/Mage/Thief): ";
    std::cin >> type;

    // Clear the console.
    system("cls");

    // Animation of Creating the Charachter.
    // For Loop Method Used
    for (int i = 0; i <= counter; i++) {
        if (i == 0)
            cout << "Building Charachter.";
        if (i == 1)
            cout << "Building Charachter..";
        if (i == 2)
            cout << "Building Charachter...";
        if (i == 3) {
            cout << "Building Charachter....";
            break;
        }

        // Pause for 800 milliseconds.
        Sleep(800);

        // Clear the console.
        system("cls");

        // Increment the counter.
        counter++;
    }

    // Clear the console.
    system("cls");

    // Heads Up Display for character.
    HUD hud(name, gender, type);
    std::cout << "---------------------------" << std::endl;
    std::cout << "|  CHARACTER INFORMATION  |" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "|       Name: " << hud.getName();
    std::cout << "       |" << std::endl;
    std::cout << "|       Gender: " << hud.getGender();
    std::cout << "      |" << std::endl;
    std::cout << "|       Type: " << hud.getType();
    std::cout << "     |" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << " " << std::endl;

    // Created a Unique Pointer to a Dynamically-Allocated array of Player Objects
    std::unique_ptr<Player[]> players = std::make_unique<Player[]>(8);

    // Loop through each player
    for (int i = 0; i < 8; i++)
    {
        // Print a message to the console with the player's name
        std::cout << hud.getName() << " you are in a Dungeon! What do you want to do?" << std::endl;

        // Print a list of options to the console
        std::cout << "1. Go North" << std::endl;
        std::cout << "2. Go East" << std::endl;
        std::cout << "3. Go South" << std::endl;
        std::cout << "4. Go West" << std::endl;
        std::cout << "5. Attack Monster" << std::endl;
        std::cout << "6. Open Treasure Chest" << std::endl;
        std::cout << "7. Drink Potion" << std::endl;
        std::cout << "8. Quit Game" << std::endl;

        // Get the player's choice as an integer
        int choice;
        std::cin >> choice;

        // Execute the corresponding action based on the player's choice
        if (choice == 1)
        {
            players[i].goNorth();
        }
        else if (choice == 2)
        {
            players[i].goEast();
        }
        else if (choice == 3)
        {
            players[i].goSouth();
        }
        else if (choice == 4)
        {
            players[i].goWest();
        }
        else if (choice == 5)
        {
            players[i].attack();
        }
        else if (choice == 6)
        {
            players[i].openChest();
        }
        else if (choice == 7)
        {
            players[i].drinkPotion();
        }

        // If the player chooses to quit the game, call the quit() function and exit the loop
        else if (choice == 8)
        {
            players[i].quit();
            break;
        }
    }

    // Return 0 to indicate that the program has finished successfully
    return 0;
}

/*
My aim for this game was to showcase Pointers, Smart Pointers, Dynamic Arrays and Object Oriented Programming.
I think there is a big potential to add more feature to this game like having a battle between Character and Monster, and add feature such as winning the battle and losing.
Also, healing, level up and getting loot from winning battles.
laslty, including leveling up increases character stats such as health and demage.
I have stopped the game here as the scope of this assignment is to showcase Pointers, Smart Pointers, Dynamic Arrays and Object Oriented Programming.
I want to keep this game simple.
*/