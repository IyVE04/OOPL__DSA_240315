#include <iostream>
#include <string>

class StringWrapper {
    std::string* data;
public:
    // Constructor
    StringWrapper(const std::string& s) {
        data = new std::string(s);
    }
    
    // Overload assignment operator
    StringWrapper& operator=(const StringWrapper& other) {
        if (this != &other) {
            *data = *other.data; // Deep copy
        }
        return *this;
    }
    
    // Type conversion to std::string
    operator std::string() const {
        return *data;
    }
    
    ~StringWrapper() {
        delete data;
    }
};

int main() {
    StringWrapper s1("Hello");
    StringWrapper s2("World");
    
    s2 = s1; // Uses overloaded assignment operator
    
    // Implicit type conversion
    std::string str = s2;
    std::cout << "Converted string: " << str << "\n";
    
    return 0;
}