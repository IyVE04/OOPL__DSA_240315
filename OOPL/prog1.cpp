#include <iostream>
#include <string>

// 1. Class Definition: Dog
// This class is a simple blueprint for a Dog object.
class Dog {
private:
    // Simple private data members
    std::string name;
    int age;

public:
    // Simple Constructor to initialize the object
    Dog(const std::string& n, int a) {
        name = n;
        age = a;
        std::cout << "Dog object created: " << name << ", Age: " << age << std::endl;
    }

    // Method: The object's behavior
    void makeSound() const {
        std::cout << name << " says: Woof! Woof!" << std::endl;
    }

    // A simple accessor (getter) method
    std::string getName() const {
        return name;
    }
};

// Main function to demonstrate creating and using a simple object
int main() {
    // 2. Object Creation
    // Create an object named 'myDog' from the Dog class blueprint.
    Dog myDog("Sparky", 3);

    std::cout << "\n--- Using the Dog Object ---" << std::endl;

    // Call the makeSound method on the 'myDog' object
    myDog.makeSound();

    // Call the getName method
    std::cout << "My dog's name is " << myDog.getName() << "." << std::endl;

    // Create another dog object
    Dog neighborhoodDog("Max", 5);
    neighborhoodDog.makeSound();

    return 0;
}