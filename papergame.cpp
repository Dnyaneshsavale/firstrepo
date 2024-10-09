#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

std::string getComputerChoice() {
    int randomNum = rand() % 3; // Generates 0, 1, or 2
    switch (randomNum) {
        case 0: return "rock";
        case 1: return "paper";
        case 2: return "scissors";
    }
    return "";
}

std::string getUserChoice() {
    std::string choice;
    std::cout << "Enter rock, paper, or scissors: ";
    std::cin >> choice;
    return choice;
}

std::string determineWinner(const std::string& userChoice, const std::string& computerChoice) {
    if (userChoice == computerChoice) {
        return "It's a tie!";
    } else if ((userChoice == "rock" && computerChoice == "scissors") ||
               (userChoice == "paper" && computerChoice == "rock") ||
               (userChoice == "scissors" && computerChoice == "paper")) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    std::string userChoice = getUserChoice();
    std::string computerChoice = getComputerChoice();

    std::cout << "Computer chose: " << computerChoice << std::endl;
}