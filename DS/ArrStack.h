#pragma once
#include <iostream>
#include "ArrQueue.h"

using namespace std;

template<typename T>
class ArrStack : public ArrQueue<T>
{
public:
	void Push(T Value)
	{
		ArrQueue<T>::_Array.InsertAtBeginning(Value);
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
