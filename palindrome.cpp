#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool isPalindrome(const std::string& str) {
    std::string cleanedStr;
    
    // Remove non-alphanumeric characters and convert to lowercase
    for (char ch : str) {
        if (std::isalnum(ch)) {
            cleanedStr += std::tolower(ch);
        }
    }
    
    // Check if cleaned string is a palindrome
    int start = 0;
    int end = cleanedStr.length() - 1;
    
    while (start < end) {
        if (cleanedStr[start] != cleanedStr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a word or phrase: ";
    std::getline(std::cin, input);
    
    // Check if the input is a palindrome
    if (isPalindrome(input)) {
        std::cout << "\"" << input << "\" is a palindrome.\n";
    } else {
        std::cout << "\"" << input << "\" is not a palindrome.\n";
    }
    
    return 0;
}
