#include <iostream>
#include <string>

using namespace std;

class Dog {
private:
    string name;
    int age;

public:
    Dog(const string& n, int a) {
        name = n;
        age = a;
        cout << "Dog object created: " << name << ", Age: " << age << endl;
    }

    void makeSound() const {
        cout << name << " says: Woof! Woof!" << endl;
    }

    string getName() const {
        return name;
    }
};

int main() {
    Dog myDog("Sparky", 3);

    cout << "\n--- Using the Dog Object ---" << endl;

    myDog.makeSound();
    cout << "My dog's name is " << myDog.getName() << "." << endl;

    Dog neighborhoodDog("Max", 5);
    neighborhoodDog.makeSound();

    return 0;
}
