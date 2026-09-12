#pragma once
#include <iostream>
#include "Queue.h"

using namespace std;

template<typename T>
class Stack : public Queue<T>
{
public:
	void Push(T Value)
	{
		Queue<T>::_List.InsertAtBeginning(Value);
	}

	T Top()
	{
		return this->Front();
	}

	T Bootom()
	{
		return this->Back();
	}
};
