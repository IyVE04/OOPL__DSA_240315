// function_overloading.cpp
#include <iostream>
#include <string>

// Overloaded function: handles different data types
void printValue(int num) {
    std::cout << "Integer: " << num << "\n";
}

void printValue(double num) {
    std::cout << "Double: " << num << "\n";
}

void printValue(const std::string& text) {
    std::cout << "String: " << text << "\n";
}

// Function with default arguments
void greet(const std::string& name, const std::string& greeting = "Hello") {
    std::cout << greeting << ", " << name << "!\n";
}

int main() {
    printValue(42);
    printValue(3.14);
    printValue("C++ is cool");
    
    greet("Alice");          // Uses default greeting
    greet("Bob", "Welcome"); // Overrides default
    
    return 0;
}