#include <iostream>
#include "sjf.h"
#include "../loader.h"
int main(int argc, char** argv) {
    if(argc != 2){
        std::cout << "invalid number of arguments" << std::endl;
    }

    std::string dataFileName = argv[1];

    // load pcb data into a pcb queue.
    std::vector<pcb> pcbQueue = loader::getPCBQueue(dataFileName);

    // make a new sjf object
    sjf sjfScheduler(pcbQueue);
    
    double time1 = sjfScheduler.getAverageWaitingTime();
    double time2 = sjfScheduler.getAverageTurnAroundTime();

    std::cout << "Avg waiting time : " << time1 << std::endl;        
    std::cout << "Avg response time : " << time1 << std::endl;
    std::cout << "Avg t/a time : " << time2 << std::endl;

}