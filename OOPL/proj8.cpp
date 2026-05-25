// inheritance.cpp
#include <iostream>

class Animal {
public:
    virtual void speak() const {
        std::cout << "Generic animal sound\n";
    }
    virtual ~Animal() {} // Virtual destructor
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!\n";
    }
};

int main() {
    Animal* myPet = new Dog();
    myPet->speak(); // Outputs "Woof!" (runtime polymorphism)
    
    delete myPet;
    myPet = new Cat();
    myPet->speak(); // Outputs "Meow!"
    
    delete myPet;
    return 0;
}