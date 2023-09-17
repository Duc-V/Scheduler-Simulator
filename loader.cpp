#include "loader.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<pcb> loader::getPCBQueue(const std::string& filename) {
    std::vector<pcb> pcbQueue;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file " << filename << std::endl;
        return pcbQueue; // Return an empty queue on error
    }

    std::string line;
    while (std::getline(file, line)) {
        int id;
        long long burstTime;
        char comma;
        std::istringstream iss(line);

        if (iss >> id >> comma >> burstTime) {
            // std::cout << id << " " << burstTime << std::endl;
        }

        pcb pcb(id, burstTime);
        pcbQueue.push_back(pcb);
    }

    file.close();
    return pcbQueue;
}