#include "Memory.h"


Memory::Memory()
{
	this->memory = new int[1024];
}

Memory::~Memory()
{
	delete this->memory;
}

int Memory::get(unsigned int addr) const
{
	return this->memory[addr];
}

void Memory::set(unsigned int addr, int data)
{
	this->memory[addr] = data;
}
