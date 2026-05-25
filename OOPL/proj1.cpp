// simple_io.cpp
#include <iostream>
#include <string>
#include <iomanip> // Required for std::setprecision

int main() {
    // Using std::cout for output (with newline)
    std::cout << "Welcome to C++ I/O demo!\n";
    
    // Prompt user for input
    std::cout << "Enter your name: ";
    
    // Read string input (safely handles whitespace)
    std::string name;
    std::getline(std::cin, name);
    
    // Process input and output result
    std::cout << "\nHello, " << name << "! ";
    std::cout << "Your name has " << name.length() << " characters.\n";
    
    // Demonstrate formatted output
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Pi approximation: " << 3.14159 << "\n";
    
    return 0;
}