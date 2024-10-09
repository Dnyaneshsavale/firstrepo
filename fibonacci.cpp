#include <iostream>

int main() {
    int terms;

    // Prompt the user to enter the number of terms
    std::cout << "Enter the number of terms in the Fibonacci series: ";
    std::cin >> terms;

    // Validate input
    if (terms <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1; // Exit with an error code
    }

    // Generate and display the Fibonacci series
    long long first = 0, second = 1, next;

    std::cout << "Fibonacci Series: ";

    for (int i = 1; i <= terms; ++i) {
        if (i == 1) {
            std::cout << first << " "; // First term
            continue;
        }
        if (i == 2) {
            std::cout << second << " "; // Second term
            continue;
        }
        next = first + second; // Calculate the next term
        first = second;        // Update first and second
        second = next;

        std::cout << next << " "; // Display the next term
    }

    std::cout << std::endl;

    return 0; // Successful completion
}
