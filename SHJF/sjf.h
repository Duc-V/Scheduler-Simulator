#ifndef sjf_H
#define sjf_H

#include <iostream>
#include "../pcb.h"
#include <queue>


class sjf{
    private:
        std::vector<pcb>  pcbQueue;
        double queueSize;
    public:
        
        sjf(std::vector<pcb> pcbQueue);
        double getAverageWaitingTime();
        double getAverageTurnAroundTime();

    static bool compareByBurstTime(pcb& a, pcb& b) {
        return a.getBurstTime() < b.getBurstTime();
    }
};

#endif