#ifndef LOADER_H
#define LOADER_H
#include <vector>
#include "pcb.h"


class loader {
public:
    static bool getPCBQueue(std::vector<pcb>& pcbQueue, const std::string& filename);
    static bool isNumber(const std::string& str); 
};

#endif 