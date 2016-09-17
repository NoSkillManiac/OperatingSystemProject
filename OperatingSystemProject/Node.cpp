#include "Node.h"

template <class T>
Node<T>::Node(T value)
{
	this->data = value;
}

template <class T>
Node<T>::~Node()
{
	delete this->next;
}

template <class T>
T Node<T>::getData() const
{
	return this->data;
}

template <class T>
void Node<T>::setData(T data)
{
	this->data = data;
}

template <class T>
Node<T>* Node<T>::getNext()
{
	return this->next;
}

template <class T>
void Node<T>::setNext(Node<T>* next)
{
	this->next = next;
}