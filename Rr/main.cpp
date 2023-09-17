#include <iostream>
#include "rr.h"
#include "../loader.h"
#include <regex>


bool isNumber(const std::string& str) {
    std::regex pattern("^[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?$");
    return std::regex_match(str, pattern);
}

int main(int argc, char** argv) {
    if(argc != 3){
        std::cout << "invalid number of arguments" << std::endl;
    }

    std::string quantumTime = argv[1];
    std::string dataFileName = argv[2];

    if (!isNumber(quantumTime)) {
        std::cout << "Invalid quantum time" << std::endl;
    }
    
    // load pcb data into a pcb queue.
    std::vector<pcb> pcbQueue = loader::getPCBQueue(dataFileName);

    // start scheduling
    rr rrScheduler(pcbQueue);
    rrScheduler.start(std::stoi(quantumTime));
}

