#include <iostream>
#include <string>

<<<<<<< HEAD:OOPL/clsobj.cpp
// class defined
class Dog {
private:
    // private data members
    std::string name;
    int age;

public:
    // Constructor
    Dog(const std::string& n, int a) {
=======
using namespace std;

class Dog {
private:
    string name;
    int age;

public:
    Dog(const string& n, int a) {
>>>>>>> dca042a65f141e500ca613b6f80db7f33655fcf8:OOPL/prog1.cpp
        name = n;
        age = a;
        cout << "Dog object created: " << name << ", Age: " << age << endl;
    }

    void makeSound() const {
        cout << name << " says: Woof! Woof!" << endl;
    }

<<<<<<< HEAD:OOPL/clsobj.cpp
    // getter method
    std::string getName() const {
=======
    string getName() const {
>>>>>>> dca042a65f141e500ca613b6f80db7f33655fcf8:OOPL/prog1.cpp
        return name;
    }
};

<<<<<<< HEAD:OOPL/clsobj.cpp

int main() {
    // Object Creation
=======
int main() {
>>>>>>> dca042a65f141e500ca613b6f80db7f33655fcf8:OOPL/prog1.cpp
    Dog myDog("Sparky", 3);

    cout << "\n--- Using the Dog Object ---" << endl;

<<<<<<< HEAD:OOPL/clsobj.cpp
    // Call the makeSound method
=======
>>>>>>> dca042a65f141e500ca613b6f80db7f33655fcf8:OOPL/prog1.cpp
    myDog.makeSound();
    cout << "My dog's name is " << myDog.getName() << "." << endl;

    Dog neighborhoodDog("Max", 5);
    neighborhoodDog.makeSound();

    return 0;
}
