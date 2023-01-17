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