#include "loader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

// split string and check format
bool splitString(int & id, long long & burstTime ,const std::string &input) {
    std::istringstream tokenStream(input);
    std::string firstStr, secondStr;

    while (std::getline(tokenStream, firstStr, ',')) {
        if (!std::getline(tokenStream, secondStr, ',')) {
            std::cout << "Error: Expected two numbers separated by a comma. " << "line : " << input << std::endl;
            return false;
        }

        if (tokenStream.peek() == ',' || !tokenStream.eof()) {
            std::cout << "Error: Too many items " << "line : " << input << std::endl;
            return false;
        }

        if (!loader::isNumber(firstStr) || !loader::isNumber(secondStr)) {
            std::cout << "Error: Both elements must be numbers. " << "line : " << input << std::endl;
            return false;
        }

        id = std::stoi(firstStr);
        burstTime = std::stoll(secondStr);
    }

    return true;
}


bool loader::getPCBQueue(std::vector<pcb>& pcbQueue, const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Cannot find file " << filename << std::endl;
        return false; // Return an empty queue on error
    }
    int id;
    long long burstTime;
    std::string line;

    // populate the pcb queue
    while (std::getline(file, line)) {
        if (!splitString(id, burstTime ,line))
            return false;

        pcb pcb(id, burstTime);
        pcbQueue.push_back(pcb);
    }

    file.close();
    return true;
}

bool loader::isNumber(const std::string& str) {
    std::regex pattern("^[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?$");
    return std::regex_match(str, pattern);
}

