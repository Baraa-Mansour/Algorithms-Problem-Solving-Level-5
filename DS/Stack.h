#pragma once
#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

template<typename T>
class Stack
{
private:
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
		this->_List.InsertAtBeginning(Value);
	}

	T Pop()
	{
		T Value = this->Top();

		this->_List.DeleteFirstNode();

		return Value;
	}

	void Print()
	{
		_List.Print();
	}

	T Top()
	{
		return this->_List.GetValue(0);
	}

	T Bootom()
	{
		return _List.GetValue(_List.Size - 1);
	}
};
