#include "fifo.h"

fifo::fifo(std::vector<pcb> pcbQueue) : pcbQueue(pcbQueue), queueSize(pcbQueue.size()) {}

double fifo::getAverageWaitingTime() {
    long currentTime = 0;
    long totalWaitTime = 0;

    // Calculate turn around time for all processes
    for (int i = 0; i < queueSize; i++) {
        if (i + 1 < queueSize) {
            pcbQueue[i + 1].setWaitingTime(currentTime + pcbQueue[i].getBurstTime());
        }
        currentTime += pcbQueue[i].getBurstTime();
        totalWaitTime += pcbQueue[i].getTotalWaitTime();
    }

    double averageWaitTime = totalWaitTime / queueSize;
    return averageWaitTime;
}

double fifo::getAverageTurnAroundTime(){
    long currentTime = 0;
    long totalTurnAroundTime = 0;
    // calculate turn around time for all processes
    for(int i = 0; i < queueSize; i++){
        pcbQueue[i].setWaitingTime(currentTime  + pcbQueue[i].getBurstTime());
        currentTime += pcbQueue[i].getBurstTime();
        totalTurnAroundTime += pcbQueue[i].getTotalWaitTime();
    }
    
    double averageTurnaroundTime = totalTurnAroundTime / queueSize;
    return averageTurnaroundTime; 
}
