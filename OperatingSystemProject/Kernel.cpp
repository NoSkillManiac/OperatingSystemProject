#include "Kernel.h"


Kernel::Kernel(Memory* virtualram, Disk* virtualdisk, std::vector<unsigned int, std::allocator<char32_t>>* directory)
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

	//initialize the long term scheduler
	this->lts = new LTS();

	//Initialize short term scheduler
	this->sts = new STS();
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
