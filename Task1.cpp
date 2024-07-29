#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    // Generate a random number between 1 and 100
    int target = std::rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have selected a number between 1 and 100. Try to guess it!\n";

    // Main game loop
    while (guess != target) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < target) {
            std::cout << "Too low! Try again.\n";
        } else if (guess > target) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        }
    }
rr
    return 0;
}

