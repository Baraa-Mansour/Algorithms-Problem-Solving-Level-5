#pragma once
#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

template<typename T>
class Queue
{
protected:
	DoubleLinkedList<T> _List;

public:
	bool IsEmpty()
	{
		return this->_List.IsEmpty();
	}

	int Size()
	{
		return this->_List.Size;
	}

	void Push(T Value)
	{
		this->_List.InsertAtEnd(Value);
	}

	T Pop()
	{
		T Value = this->Front();

		this->_List.DeleteFirstNode();

		return Value;
	}

	void Print()
	{
		_List.Print();
	}

	T Front()
	{
		return this->_List.GetValue(0);
	}

	T Back()
	{
		return _List.GetValue(_List.Size - 1);
	}
};
