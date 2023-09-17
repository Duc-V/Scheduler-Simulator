#include "pcb.h"

pcb::pcb(int id, long burstTime) : id(id), burstTime(burstTime), remainingTime(burstTime), totalWaitTime(0), responseTime(0), turnAroundTime(0) {}

long long pcb::getBurstTime() {
    return burstTime;
}


long long pcb::getRemainingTime() {
    return remainingTime;
}

long long pcb::getTotalWaitTime() {
    return totalWaitTime;
}

long long  pcb::getId(){
    return id;
};

long long pcb::getTurnAroundTime(){
    return turnAroundTime;
}

long long pcb::getResponseTime(){
    return responseTime;
}

void pcb::setWaitingTime(long long time) {
    totalWaitTime = time;
}

void pcb::setRemainingTime(long long time) {
    remainingTime = time;
}

void pcb::setReponseTime(long long time){
    responseTime = time;
}


void pcb::setTurnAroundTime(long long time){
    turnAroundTime = time;
}


