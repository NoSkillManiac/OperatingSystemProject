#include "PCB.h"

PCB::PCB()
{
	processes = new std::vector<ProcessInfo*>();
}


PCB::~PCB()
{
	//delete all the PInfo objects
	for (int i = 0; i < processes->size(); i++)
	{
		ProcessInfo* pi = (*processes)[i];
		delete pi;
	}
	delete processes;
}

void PCB::AddProcess(ProcessInfo* pi)
{
	processes->push_back(pi);
}

ProcessInfo* PCB::RemProcess(int index)
{
	for (int i = 0; i < processes->size(); i++)
	{
		ProcessInfo* pi = (*processes)[i];
		if (pi->pid == index)
		{
			processes->erase(processes->begin() + i);
			return pi;
		}
	}
}

ProcessInfo* PCB::GetProcess(int index)
{
	for (int i = 0; i < processes->size(); i++)
	{
		ProcessInfo* pi = (*processes)[i];
		if (pi->pid == index)
		{
			return pi;
		}
	}
}