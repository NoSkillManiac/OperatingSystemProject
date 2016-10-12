#include "PID.h"
#include "Node.h"
#include <vector>
#include "Disk.h"

#pragma once
class LTS
{
public: 
	LTS();
	~LTS();
	void addToQueue(PID pid); //adds to LinkedList
	void removeFrom(PID pid); //Removes from LinkedList
	void assignProcessor(unsigned int i); //If 1 processor, always uses 0
	void checkBalance(); //checks the balance of the CPU load if multiple processors
private:
	PID *conBlock;
	Node<PID>* pList;
};
