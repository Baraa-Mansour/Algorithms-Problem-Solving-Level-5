#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Queue
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
		this->_List.InsertAtEnd(Value);
	}

	T Pop()
	{
		T Value = this->Back();

		this->_List.DeleteLastnode();

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
