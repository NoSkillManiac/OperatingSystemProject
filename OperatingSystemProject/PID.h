#pragma once
enum ProcessState
{
	STARTING,
	RUNNING,
	WAITING,
	BLOCKED,
	TERMINATED
};

class PID
{
public:
	PID();
	~PID();

	ProcessState getState(PID pid);
	void setState(PID pid, int s);
	int getID(PID pid);

	int id;
	ProcessState state;
	unsigned int program_file;
	unsigned short counter;
	int* registers; //The 14 registers (0-13)
	unsigned short base_addr;
	unsigned short end_addr;
	int num_instructions;
	int num_data;
	int num_other;
	unsigned long cputime;
	unsigned long waittime;
};

