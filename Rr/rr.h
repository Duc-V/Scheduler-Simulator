#ifndef rr_H
#define rr_H

#include <iostream>
#include "../pcb.h"
#include <queue>


class rr{
    private:
        std::vector<pcb>  pcbQueue;
        double queueSize;
    public:
        rr(std::vector<pcb> pcbQueue);
        void start(int quantumTime);
};

#endif