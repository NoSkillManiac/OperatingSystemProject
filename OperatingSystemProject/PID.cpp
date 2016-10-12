#include "PID.h"


PID::PID()
{
	registers = new int[14];
}


PID::~PID()
{
	delete registers;
}


ProcessState PID::getState(PID pid)
{
	return state;
}

void PID::setState(PID pi, int s)
{
	state = ProcessState(s);
}

int PID::getID(PID pid)
{
	return id;
}