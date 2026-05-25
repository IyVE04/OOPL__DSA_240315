#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string> 
void readFile(const std::string& filename) {
    
    std::ifstream file(filename.c_str());
    
 
    if (!file) {
        throw std::runtime_error("File not found: " + filename);
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
}

int main() {
    try {
        readFile("data.txt"); 
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    
    return 0;
}