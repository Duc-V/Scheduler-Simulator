#ifndef PCB_H
#define PCB_H

#include <iostream>

#pragma once  // tells the compiler to only include this file once
              /**
 * the process control block - represents a process that needs to be executed in
 * our simulator. Please note the I used some custom types of osp2023::time_type
 * and osp2023::id_type. these are just aliases to long integers but they are
 * more meaningful type names, hinting at how they will be used. Please see
 * their definitions in types.h.
 **/
class pcb {

    int id;
    long long burstTime;
    long long remainingTime;
    long long totalWaitTime;
    long long responseTime;
    long long turnAroundTime;

   public:
    pcb(int id, long burstTime);
    // get the initial burst time
    long long  getBurstTime();
    // get the remaining burst time
    long long  getRemainingTime();
    // get the total wait time
    long long  getTotalWaitTime();
    // get process id
    long long  getId();
    // get the reponse time
    long long  getResponseTime();
    // get turn around time;
    long long  getTurnAroundTime();

    void setTurnAroundTime(long long time);
    void setReponseTime(long long time);
    void setRemainingTime(long long time);
    void setWaitingTime(long long time);

    // max and min duration for a process in our system.
    static constexpr long long  MAX_DURATION = 100;
    static constexpr long long  MIN_DURATION = 10;
};
#endif 