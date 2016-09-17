#pragma once

template <class T>
class Node
{
public:
	Node(T value);
	~Node();
	T getData() const;
	void setData(T data);
	Node<T>* getNext();
	void setNext(Node<T>* next);

private:
	Node<T>* next;
	T data;
};

