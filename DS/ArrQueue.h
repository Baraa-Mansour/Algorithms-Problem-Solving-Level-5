#pragma once
#include <iostream>
#include "DynamicArray.h"
using namespace std;

template<typename T>
class ArrQueue
{
protected:
	DynamicArray<T> _Array;

public:
	bool IsEmpty()
	{
		return this->_Array.IsEmpty();
	}

	int Size()
	{
		return this->_Array.Size;
	}

	void Push(T Value)
	{
		this->_Array.InsertAtEnd(Value);
	}

	T Pop()
	{
		T Value = this->Front();

		this->_Array.DeleteFirstItem();

		return Value;
	}

	void Print()
	{
		_Array.Print();
	}

	T Front()
	{
		return this->_Array.GetItem(0);
	}

	T Back()
	{
		return _Array.GetItem(_Array.Size - 1);
	}
};
