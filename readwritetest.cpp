#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// Function to read lines from a file into a vector
std::vector<std::string> readFileToVector(const std::string &filename) {
    std::vector<std::string> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file for reading: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) { // Skip empty lines
            data.push_back(line);
        }
    }

    file.close();
    return data;
}

// Function to write vector contents to a file
void writeVectorToFile(const std::string &filename, const std::vector<std::string> &data) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file for writing: " + filename);
    }

    for (const auto &line : data) {
        file << line << "\n";
    }

    file.close();
}

int main() {
    try {
        // Example: Read from "input.txt" into vector
        std::vector<std::string> people = readFileToVector("Employee_data.txt");

        // Display read data
        std::cout << "Data read from file:\n";
        for (const auto &line : people) {
            std::cout << line << "\n";
        }

        // Example: Write vector data to "output.txt"
        writeVectorToFile("output.txt", people);

        std::cout << "\nData successfully written to output.txt\n";
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}
