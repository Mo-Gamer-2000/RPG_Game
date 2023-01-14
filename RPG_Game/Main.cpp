#include "Player.h" // Include the header file for the Player class
#include "Monster.h"
#include "Header.h" // Include the header file for the Player class

// Class definition for the Game class
class Game
{
public:
    // Member function that displays some text and waits for the user to press Enter
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

class Intro
{
public:
    // Display Function has a Loading Screen and Displays Text.
    void display()
    {

        // Display the Loading Animation.
        for (int i = 0; i < 100; i++)
        {
            // Print the current loading percentage to the console.
            std::cout << "Loading: " << i << "%" << std::endl;

            // Pause for 1000 milliseconds divided by the frame rate.
            std::this_thread::sleep_for(std::chrono::milliseconds(1000 / kFrameRate_));

            // Clear the console.
            system("cls");
        }

        // Display the Text "WELCOME TO MY GAME".
        std::cout << "\033[1;32m" << " ___ " << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "| W |" << std::endl;
        std::cout << "| E |" << std::endl;
        std::cout << "| L |" << std::endl;
        std::cout << "| C |" << std::endl;
        std::cout << "| O |" << std::endl;
        std::cout << "| M |" << std::endl;
        std::cout << "| E |" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "| T |" << std::endl;
        std::cout << "| O |" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "| M |" << std::endl;
        std::cout << "| Y |" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "| G |" << std::endl;
        std::cout << "| A |" << std::endl;
        std::cout << "| M |" << std::endl;
        std::cout << "| E |" << std::endl;
        std::cout << "|___|" << std::endl;
        std::cout << "\033[0m" << std::endl;
    }

private:
    // Number of FPS (frames per second).
    const int kFrameRate_ = 30;
};

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

//Initialize player position
int playerX = 0;
int playerY = 0;

int main()
{
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
    std::cout << "\033[1;32m" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "|  BUILD YOUR CHARACTER  |" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "\033[0m" << std::endl;
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
    for (int i = 0; i <= counter; i++)
    {
        if (i == 0)
            cout << "Building Charachter.";
        if (i == 1)
            cout << "Building Charachter..";
        if (i == 2)
            cout << "Building Charachter...";
        if (i == 3)
        {
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

    // Create a 2-dimensional dynamic array to represent the game map
    int mapX = 10;
    int mapY = 10;
    std::unique_ptr<std::unique_ptr<Player[]>[]> map = std::make_unique<std::unique_ptr<Player[]>[]>(mapX);
    for (int i = 0; i < mapX; i++) {
        map[i] = std::make_unique<Player[]>(mapY);
    }

    // variable to check if the player wants to quit
    bool quit = false;

    // Loop through until the player chooses to quit
    while (!quit) {
        // Print a message to the console with the player's name
        std::cout << "You are in a Dungeon! What do you want to do?" << std::endl;
        std::cout << "Your current position is X: " << playerX << " Y: " << playerY << std::endl;

        // Print a list of options to the console
        std::cout << "W. Go North" << std::endl;
        std::cout << "A. Go West" << std::endl;
        std::cout << "S. Go South" << std::endl;
        std::cout << "D. Go East" << std::endl;
        std::cout << "5. Attack Monster" << std::endl;
        std::cout << "6. Open Treasure Chest" << std::endl;
        std::cout << "7. Drink Potion" << std::endl;
        std::cout << "8. Quit Game" << std::endl;

        // Get the player's choice as a character
        char choice;
        std::cin >> choice;
        choice = toupper(choice);

        // Execute the corresponding action based on the player's choice
        if (choice == 'W')
        {
            if (playerY > 0) {
                map[playerX][playerY].goNorth();
                playerY--;
            }
            else {
                std::cout << "Cannot go North, Out of Map" << std::endl;
                continue;
            }
        }
        else if (choice == 'A')
        {
            if (playerX > 0) {
                map[playerX][playerY].goWest();
                playerX--;
            }
            else {
                std::cout << "Cannot go West, Out of Map" << std::endl;
                continue;
            }
        }
        else if (choice == 'S')
        {
            if (playerY < mapY - 1) {
                map[playerX][playerY].goSouth();
                playerY++;
            }
            else {
                std::cout << "Cannot go South, Out of Map" << std::endl;
                continue;
            }
        }
        else if (choice == 'D')
        {
            if (playerX < mapX - 1) {
                map[playerX][playerY].goEast();
                playerX++;
            }
            else {
                std::cout << "Cannot go East, Out of Map" << std::endl;
                continue;
            }
        }
        else if (choice == '5')
        {
            map[playerX][playerY].attack();
        }
        else if (choice == '6')
        {
            map[playerX][playerY].openChest();
        }
        else if (choice == '7')
        {
            map[playerX][playerY].drinkPotion();
        }
        else if (choice == '8')
        {
            map[playerX][playerY].quit();
            quit = true;
        }
    }
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