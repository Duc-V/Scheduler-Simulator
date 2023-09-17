#include "rr.h"
#include <vector>

rr::rr(std::vector<pcb> pcbQueue) : pcbQueue(pcbQueue), queueSize(pcbQueue.size()) {}


void rr::start(int quantumTime) {
    long remainingPCB = queueSize;
    int currentTime = 0;
    int lastPCB;

    // iterate until no remaining pcb with burst time
    while (remainingPCB != 0){
        for (int i = 0; i < queueSize; i++) {
            if(i != 0 && pcbQueue[i].getResponseTime() == 0){
                pcbQueue[i].setReponseTime(pcbQueue[i].getTotalWaitTime());
            }

            // if current pcb still have remaining burst time
            if(pcbQueue[i].getRemainingTime() !=0 ){

                // calculate the execution time for the current pcb
                long executionTime = std::min(quantumTime, int(pcbQueue[i].getRemainingTime()));

                // update the current time
                currentTime += executionTime;

                // update the current pcb remaining burst time
                pcbQueue[i].setRemainingTime(pcbQueue[i].getRemainingTime() - executionTime);
                
                // if current pcb remaining time is 0, update remaining pcb
                if(pcbQueue[i].getRemainingTime() == 0){
                    pcbQueue[i].setTurnAroundTime(currentTime);
                    remainingPCB--;
                }
                // update the wait time for all other pcbs that still have burst remaining
                for(int j = 0; j < queueSize; j++){
                    if(j != i && pcbQueue[j].getRemainingTime() !=0 ){
                        pcbQueue[j].setWaitingTime(pcbQueue[j].getTotalWaitTime() + executionTime);
                    }
                }    
            }
        }
    }

    // calculate average times
    double averageWaitTime;
    double averageResponseTime;
    double avaerageTurnAroundTime;


    for(int i = 0; i < queueSize; i++){
        averageWaitTime += pcbQueue[i].getTotalWaitTime();
        averageResponseTime += pcbQueue[i].getResponseTime();
        avaerageTurnAroundTime += pcbQueue[i].getTurnAroundTime();
    }

    avaerageTurnAroundTime = avaerageTurnAroundTime / queueSize;
    averageResponseTime = averageResponseTime /queueSize;
    averageWaitTime = averageWaitTime / queueSize; 
    
    std::cout << "Avg response time : "<< averageResponseTime << std::endl;
    std::cout << "Avg waiting time : "<< averageWaitTime << std::endl;
    std::cout << "Avg t/a time : "<< avaerageTurnAroundTime << std::endl;
}

