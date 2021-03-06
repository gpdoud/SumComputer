#include <iostream>
#include <string>
#include "Computer.h"
#include "IntClock.h"
#include "Logger.h"
#include "Jobs.h"
#include "Job.h"

void log(std::string msg) {
    Logger::log(msg);
}
void get_job_to_run(Jobs &jobs) {
//
    Job *j1 = new Job("Job1 10 cycles");
    Process* p1 = new Process();
    p1->set_req_cycles(10);
    j1->add_process(p1);
    jobs.Push(j1);
//
//
    Job* j2 = new Job("Job2 33 cycles");
    Process* p2_1 = new Process();
    p2_1->set_req_cycles(11);
    j2->add_process(p2_1);
    Process* p2_2 = new Process();
    p2_2->set_req_cycles(22);
    j2->add_process(p2_2);
    jobs.Push(j2);
//
//
    Job* j3 = new Job("Job3 66 cycles");
    Process* p3_1 = new Process();
    p3_1->set_req_cycles(11);
    j3->add_process(p3_1);
    Process* p3_2 = new Process();
    p3_2->set_req_cycles(22);
    j3->add_process(p3_2);
    Process* p3_3 = new Process();
    p3_3->set_req_cycles(33);
    j3->add_process(p3_3);
    jobs.Push(j3);
//
//
    Job* j4 = new Job("Job4 110 cycles");
    Process* p4_1 = new Process();
    p4_1->set_req_cycles(11);
    j4->add_process(p4_1);
    Process* p4_2 = new Process();
    p4_2->set_req_cycles(22);
    j4->add_process(p4_2);
    Process* p4_3 = new Process();
    p4_3->set_req_cycles(33);
    j4->add_process(p4_3);
    Process* p4_4 = new Process();
    p4_4->set_req_cycles(44);
    j4->add_process(p4_4);
    jobs.Push(j4);
//
}
int main() {

    Computer comp;

    Config cfg;
    comp.boot_up(&cfg);

    Jobs jobs;
    get_job_to_run(jobs);
    comp.load_jobs(&jobs);

    comp.run();

    comp.shut_down();
}