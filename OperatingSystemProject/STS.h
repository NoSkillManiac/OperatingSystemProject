#include "LTS.h"
#include "Node.h"
#include "Processor.h"
#include "PID.h"

#pragma once
class STS
{
public:
	STS();
	~STS();
	void addToQueue(PID pid); // adds to linkedlist
	void removeFrom(PID pid); // removes from linked list
	void interrupt(PID pid); //sends interrupt signal to processor in case of higher priority.
	void action(PID pid); //determines action to be taken after checkstate
	void incPriority(PID pid); //increases priority after a certian wait time; DOES NOT NEED IMPLEMENTATION YET

private:
	ProcessState checkState(PID pid); //Checks process state to determine action
	unsigned long checkCTme(PID pid); //checks time on CPU for each process
	unsigned long checkWTime(PID pid); //checks time in queue
	Node<PID>* pList;
	PID id;
};
