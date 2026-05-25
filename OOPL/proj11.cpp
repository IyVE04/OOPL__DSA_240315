// templates.cpp
#include <iostream>
#include <vector>

// Function template for finding maximum
template <typename T>
T findMax(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// Class template for container
template <typename T>
class Container {
    T value;
public:
    Container(const T& v) : value(v) {}
    void print() const {
        std::cout << "Value: " << value << "\n";
    }
};

int main() {
    // Function template usage
    std::cout << "Max int: " << findMax(3, 7) << "\n";
    std::cout << "Max double: " << findMax(3.14, 2.71) << "\n";
    
    // Class template usage
    Container<int> intContainer(42);
    Container<std::string> strContainer("C++ Templates");
    
    intContainer.print();
    strContainer.print();
    
    return 0;
}