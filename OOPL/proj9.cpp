#include <iostream>

// Abstract interface (pure virtual class)
class Drawable {
public:
    virtual void draw() const = 0; // Pure virtual function
    virtual ~Drawable() {}
};

class Circle : public Drawable {
    int radius;
public:
    Circle(int r) : radius(r) {}
    void draw() const override {
        std::cout << "Drawing circle with radius " << radius << "\n";
    }
};

class Square : public Drawable {
    int side;
public:
    Square(int s) : side(s) {}
    void draw() const override {
        std::cout << "Drawing square with side " << side << "\n";
    }
};

int main() {
    Drawable* shapes[2] = {
        new Circle(5),
        new Square(10)
    };
    
    for (auto shape : shapes) {
        shape->draw();
    }
    
    for (auto shape : shapes) delete shape;
    
    return 0;
}