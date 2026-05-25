// simple_class.cpp
#include <iostream>
#include <string>

// Logical grouping for related classes
namespace VehicleSystem {
    class Car {
    private:
        std::string model;
        int year;
        
    public:
        // Constructor
        Car(const std::string& m, int y) : model(m), year(y) {}
        
        // Member function
        void displayInfo() const {
            std::cout << "Car: " << model << " (" << year << ")\n";
        }
    };
}

int main() {
    // Create objects in namespace
    VehicleSystem::Car tesla("Model 3", 2023);
    VehicleSystem::Car ford("F-150", 2022);
    
    tesla.displayInfo();
    ford.displayInfo();
    
    return 0;
}