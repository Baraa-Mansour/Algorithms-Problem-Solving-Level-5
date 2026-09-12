#pragma once
#include <iostream>
using namespace std;

template<typename T>
class DynamicArray
{
private:
	T* _Array;
	int _Size;

	bool _IsValidIndex(int Index)
	{
		return (Index >= 0) && (Index < this->Size);
	}

public:
	DynamicArray(int Size)
	{
		this->_Size = Size >= 0 ? Size : 0;

		_Array = new T[this->Size];
	}

	~DynamicArray()
	{
		delete[] _Array;
	}

	bool IsEmpty()
	{
		return this->Size == 0;
	}

	int GetSize()
	{
		return this->_Size;
	}
	__declspec(property(get = GetSize))int Size;

	void ReSize(int NewSize)
	{
		if (NewSize < 0)
			return;

		T* Temp = new T[NewSize];
		int MinSize = NewSize > this->Size ? this->Size : NewSize;

		for (int i = 0; i < MinSize; i++)
		{
			Temp[i] = _Array[i];
		}

		this->_Size = NewSize;
		delete[] _Array;
		_Array = Temp;
	}

	bool SetItem(int Index, T Value)
	{
		if (this->_IsValidIndex(Index))
		{
			this->_Array[Index] = Value;
			return true;
		}
		return false;
	}

	T GetItem(int Index)
	{
		if (!_IsValidIndex(Index))
			return NULL;

		return _Array[Index];
	}

	void Reverse()
	{
		for (int i = 0; i < this->Size / 2; i++)
		{
			T &First = _Array[i], &Last = _Array[this->Size - 1 - i];

			T Temp = First;
			First = Last;
			Last = Temp;
		}
	}

	void Clear()
	{
		delete[] _Array;

		this->_Size = 0;
		_Array = new T[0];
	}

	void Print()
	{
		for (int i = 0; i < this->Size ; i++)
			cout << _Array[i] << " ";
		cout << endl;
	}
};
