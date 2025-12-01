#include <iostream>
#include <string>
#include <iomanip> // Required for setting precision for price

// 1. Class Definition: Book
// A class is a blueprint for creating objects (a particular book).
class Book {
private:
    // Data Members (Attributes) - Usually kept private for encapsulation
    std::string title;
    std::string author;
    std::string isbn;
    double price;

public:
    // Constructor - A special method to initialize the object when it is created.
    // It takes arguments to set the initial state of the data members.
    Book(const std::string& t, const std::string& a, const std::string& i, double p)
        : title(t), author(a), isbn(i), price(p) {
        // Initialization list is used above (e.g., title(t)).
        std::cout << "A new book object created: " << title << std::endl;
    }

    // Method 1: Display Details
    // This method shows the data stored in the object.
    void displayDetails() const {
        std::cout << "\n--- Book Details ---" << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
        // Use fixed and setprecision to format the price display
        std::cout << "Price: $" << std::fixed << std::setprecision(2) << price << std::endl;
        std::cout << "--------------------" << std::endl;
    }

    // Method 2: Apply Discount
    // This method modifies the object's internal state (the price data member).
    void applyDiscount(double percentage) {
        if (percentage > 0 && percentage <= 100) {
            double discountAmount = price * (percentage / 100.0);
            price -= discountAmount;
            std::cout << "Applied " << percentage << "% discount to " << title << ". New price is $" << price << std::endl;
        } else {
            std::cout << "Invalid discount percentage." << std::endl;
        }
    }

    // Method 3: Getter Method (Accessor)
    // A method to safely retrieve the value of a private data member.
    double getPrice() const {
        return price;
    }
};

// Main function to demonstrate creating and using objects
int main() {
    // 2. Object Creation (Instantiation)
    // book1 and book2 are objects (instances) of the Book class.

    // Create the first Book object
    Book book1("The Art of Programming", "A. Coder", "978-1234567890", 49.99);

    // Create the second Book object
    Book book2("A Deep Dive into Algorithms", "B. Analyst", "978-0987654321", 75.50);

    // 3. Object Interaction (Calling Methods)
    std::cout << "\n--- Using Objects ---" << std::endl;

    // Call methods on book1
    book1.displayDetails();
    book1.applyDiscount(15.0); // Apply a 15% discount
    book1.displayDetails();

    std::cout << "\n--- Using book2 ---" << std::endl;

    // Call methods on book2
    book2.displayDetails();
    std::cout << book2.author << " is the author" << std::endl; // ERROR: This would fail because 'author' is private.
    std::cout << "Current price of " << book2.title << " is: $" << book2.getPrice() << std::endl;

    return 0;
}