#include <iostream>
#include <string>

// class defined
class Dog {
private:
    // private data members
    std::string name;
    int age;

public:
    // Constructor
    Dog(const std::string& n, int a) {
        name = n;
        age = a;
        std::cout << "Dog object created: " << name << ", Age: " << age << std::endl;
    }

    // Method: The object's behavior
    void makeSound() const {
        std::cout << name << " says: Woof! Woof!" << std::endl;
    }

    // getter method
    std::string getName() const {
        return name;
    }
};


int main() {
    // Object Creation
    Dog myDog("Sparky", 3);

    std::cout << "\n--- Using the Dog Object ---" << std::endl;

    // Call the makeSound method
    myDog.makeSound();

    // Call the getName method
    std::cout << "My dog's name is " << myDog.getName() << "." << std::endl;

    // Create another dog object
    Dog neighborhoodDog("Max", 5);
    neighborhoodDog.makeSound();

    return 0;
}