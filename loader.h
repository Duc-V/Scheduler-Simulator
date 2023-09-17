#ifndef LOADER_H
#define LOADER_H
#include <vector>
#include "pcb.h"


class loader {
public:
    static std::vector<pcb> getPCBQueue(const std::string& filename);
};

#endif 