#include "Kernel.h"


Kernel::Kernel(Memory* virtualram, Disk* virtualdisk, std::vector<unsigned int>* directory)
{
	//accept the parameters
	this->files = directory;
	this->ram = virtualram;
	this->hdd = virtualdisk;

	//initialize the pcb
	this->pcb = new PCB();

	//initialize the processor(s)
	this->processors = new Processor*[NUM_PROCESSORS];
	for (int i = 0; i < NUM_PROCESSORS; i++)
	{
		this->processors[i] = new Processor(virtualram);
	}

	//TODO: Initialize long term scheduler
	//TODO: Initialize short term scheduler
}


Kernel::~Kernel()
{
	//dispose of cpus
	for (int i = 0; i < NUM_PROCESSORS; i++)
	{
		Processor* proc = &(this->processors[i]);
		delete proc;
	}
	delete this->processors;

	//dispose of data structures
	delete files;
	delete ram;
	delete hdd;
	delete pcb;
}
