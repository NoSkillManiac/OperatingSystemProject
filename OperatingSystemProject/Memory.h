#pragma once
class Memory
{
public:
	Memory();
	~Memory();

	int get(unsigned int addr) const;
	void set(unsigned int addr, int data);

private:
	int* memory;
};

