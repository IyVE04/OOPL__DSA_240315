#include <iostream>
#include <string>

class Logger {
private:
    std::string name;
    
public:
    // Regular constructor
    Logger(const std::string& n) : name(n) {
        std::cout << "Logger created: " << name << "\n";
    }
    
    // Copy constructor (deep copy)
    Logger(const Logger& other) : name(other.name + "_copy") {
        std::cout << "Logger copied: " << name << "\n";
    }
    
    // Destructor
    ~Logger() {
        std::cout << "Logger destroyed: " << name << "\n";
    }
};

int main() {
    Logger mainLog("Main");
    Logger copyLog = mainLog; // Triggers copy constructor
    
    // Copy constructor also called here
    Logger anotherLog = copyLog;
    
    return 0;
}