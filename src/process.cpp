#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>
#include <bits/stdc++.h>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// I implemented : Return this process's ID --------------------------
int Process::Pid() { 
    return this->PID_ ; }

// I implemented : Return this process's CPU utilization -------------------
float Process::CpuUtilization() { 
    float uptime = LinuxParser::UpTime(PID_);
    float ActiveJiffSecs = LinuxParser::ActiveJiffies(PID_);
    float Sysuptime = LinuxParser::UpTime();
    float seconds = (Sysuptime - uptime);
    float CPU_Use;
    if (seconds > 0) CPU_Use = ActiveJiffSecs/(seconds*sysconf(_SC_CLK_TCK));
    return CPU_Use;
    }

// I implemented : Return the command that generated this process -----------------
string Process::Command() { return LinuxParser::Command(PID_); }

// I implemented : Return this process's memory utilization -----------
string Process::Ram() { 
    string ram = LinuxParser::Ram(PID_);
    std::stringstream ramstream(ram);
    ramstream >> ram_; //storing value of Ram into private float variable ram_
    return ram; }

// I implemented : Return the user (name) that generated this process ----------
string Process::User() { return LinuxParser::User(PID_); }

// I implemented : Return the age of this process (in seconds) -----------------
long int Process::UpTime() { return LinuxParser::UpTime(PID_); }

// I implemented : Overload the "less than" comparison operator for Process objects------------
bool Process::operator<(Process const& a) const { 
    return (a.ram_> this->ram_) ;
    }