#include "ProcessInfo.h"
#include <vector>

#pragma once
class PCB
{
public:
	PCB();
	~PCB();
	void AddProcess(ProcessInfo* pi);
	ProcessInfo* RemProcess(int pid);
	ProcessInfo* GetProcess(int pid);

private:
	std::vector<ProcessInfo*>* processes;
};

