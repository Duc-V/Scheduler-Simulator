#ifndef FIFO_H
#define FIFO_H

#include <iostream>
#include "../pcb.h"
#include <queue>


class fifo{
    private:
        std::vector<pcb>  pcbQueue;
        double queueSize;
    public:
        fifo(std::vector<pcb>  pcbQueue);
        double getAverageWaitingTime();
        double getAverageTurnAroundTime();
};

#endif