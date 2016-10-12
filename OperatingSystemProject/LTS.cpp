#include "LTS.h"
#include "Node.h"


LTS::LTS()
{
	this->pList = NULL;
}

LTS::~LTS()
{
	while (pList->getNext() != NULL)
	{
		Node<PID> *t = pList;
		pList = pList -> getNext();
		delete t;
	}

}

void LTS::addToQueue(PID pid) //adds to end of queue
{
	Node<PID> *t = new Node<PID>(pid);
	while (pList -> getNext() != NULL)
		pList = pList ->getNext();
	pList -> setNext(t);
}

void LTS::removeFrom(PID pid)
{
	Node<PID> *t;
	if (pid.getID(pList -> getData()) == pid.getID(pid))
	{
		t = pList;
		pList = pList -> getNext();
		delete t;
	}
	else
		while (pList -> getNext() != NULL)
			if (pid.getID(pList -> getNext() -> getData()) == pid.getID(pid))
			{
				t = pList -> getNext();
				pList -> setNext(t->getNext());
				delete t;
			}
			else
				pList = pList -> getNext();
				
}

void LTS::assignProcessor(unsigned int i)
{
	//May not need implementation
}

void LTS::checkBalance()
{
	//may not need implementation
}