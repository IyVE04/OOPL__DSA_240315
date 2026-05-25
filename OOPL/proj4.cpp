#include <iostream>
#include <cstring>

class DynamicString {
private:
    char* data; // Pointer to dynamically allocated memory
    
public:
    // 1. Standard Constructor
    DynamicString(const char* str) {
        if (str) {
            // Dropped std:: prefix for compatibility
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }
    
    // 2. Copy Constructor (Deep Copy)
    DynamicString(const DynamicString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }
    
    // 3. Copy Assignment Operator (Strong Exception Safety)
    DynamicString& operator=(const DynamicString& other) {
        // Prevent self-assignment
        if (this != &other) {
            // Step 1: Allocate new memory FIRST
            char* newData = new char[strlen(other.data) + 1];
            strcpy(newData, other.data);
            
            // Step 2: Now it is safe to delete the old memory
            delete[] data;
            
            // Step 3: Update the pointer
            data = newData;
        }
        return *this;
    }
    
    // 4. Destructor
    ~DynamicString() {
        delete[] data;
    }
    
    void print() const {
        std::cout << data << "\n";
    }
};

int main() {
    DynamicString hello("Hello, World!");
    DynamicString cpp("C++ Memory Demo");
    
    hello.print();
    cpp.print();
    
    DynamicString safeCopy = hello; 
    safeCopy.print(); 
    
    return 0;
}