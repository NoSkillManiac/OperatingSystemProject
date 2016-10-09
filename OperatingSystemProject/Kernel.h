#include "PCB.h"
#include "Processor.h"
#include "Memory.h"
#include "Disk.h"
#include <vector>

#define NUM_PROCESSORS 1

#pragma once
class Kernel
{
public:
	Kernel(Memory* virtualram, Disk* virtualdisk, std::vector<unsigned int>* directory);
	~Kernel();

private:
	Processor** processors;
	PCB* pcb;
	Memory* ram;
	Disk* hdd;
	std::vector<unsigned int>* files;
};

