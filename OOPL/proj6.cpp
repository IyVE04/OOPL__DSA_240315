// operator_overloading.cpp
#include <iostream>

class Vector {
    int x, y;
public:
    Vector(int x = 0, int y = 0) : x(x), y(y) {}
    
    // Overload + operator
    Vector operator+(const Vector& v) const {
        return Vector(x + v.x, y + v.y);
    }
    
    // Friend function for << operator
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};

// Implementation outside class
std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main() {
    Vector v1(2, 3);
    Vector v2(4, 5);
    
    std::cout << "v1: " << v1 << "\n";
    std::cout << "v2: " << v2 << "\n";
    std::cout << "v1 + v2 = " << (v1 + v2) << "\n";
    
    return 0;
}
#include <iostream>

class Vector {
    int x, y;
public:
    Vector(int x = 0, int y = 0) : x(x), y(y) {}
    
    // Overload + operator
    Vector operator+(const Vector& v) const {
        return Vector(x + v.x, y + v.y);
    }
    
    // Friend function for << operator
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};

// Implementation outside class
std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main() {
    Vector v1(2, 3);
    Vector v2(4, 5);
    
    std::cout << "v1: " << v1 << "\n";
    std::cout << "v2: " << v2 << "\n";
    std::cout << "v1 + v2 = " << (v1 + v2) << "\n";
    
    return 0;
}