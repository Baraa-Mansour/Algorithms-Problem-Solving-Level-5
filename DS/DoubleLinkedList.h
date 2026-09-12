#pragma once
#include<iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
public:
	class Node
	{
	private:
		T _Value;
		Node* _Next;
		Node* _Prev;

	public:
		Node()
		{
			this->Next = NULL;
			this->_Prev = NULL;
		}
		Node(T Value, Node* Next, Node* Prev)
		{
			this->Value = Value;
			this->Next = Next;
			this->_Prev = Prev;
		}

		T GetValue()
		{
			return this->_Value;
		}
		void SetValue(T Value)
		{
			this->_Value = Value;
		}

		Node* GetNext()
		{
			return this->_Next;
		}
		void SetNext(Node* Next)
		{
			this->_Next = Next;
		}

		Node* GetPrev()
		{
			return this->_Prev;
		}
		void SetPrev(Node* Prev)
		{
			this->_Prev = Prev;
		}

		__declspec(property(get = GetValue, put = SetValue)) T Value;
		__declspec(property(get = GetNext, put = SetNext)) Node* Next;
		__declspec(property(get = GetPrev, put = SetPrev)) Node* Prev;
	};

private:
	Node* _Head = NULL;
	int _Size = 0;

	void _InsertAfter(Node* PrevNode, T NewValue)
	{
		if (PrevNode == NULL)
			return;

		Node* NewNode = new Node(NewValue, PrevNode->Next, PrevNode);

		if (PrevNode->Next != NULL)
			PrevNode->Next->Prev = NewNode;

		PrevNode->Next = NewNode;
	}

public:
	int GetSize()
	{
		return this->_Size;
	}
	__declspec(property(get = GetSize)) int Size;

	bool IsEmpty()
	{
		return this->Size == 0;
	}
	

	// Insert
	void InsertAtBeginning(T Value)
	{
		Node* NewNode = new Node(Value, NULL, NULL);

		if (_Head == NULL)
		{
			_Head = NewNode;
			this->_Size++;
			return;
		}

		NewNode->Next = _Head;
		_Head->Prev = NewNode;

		_Head = NewNode;
		this->_Size++;
	}

	void InsertAfter(T ExistingValue, T NewValue)
	{
		Node* Current = _Head;
		while (Current != NULL)
		{
			if (Current->Value == ExistingValue)
			{
				this->_InsertAfter(Current, NewValue);
				this->_Size++;

				return;
			}

			Current = Current->Next;
		}
	}

	void InsertAtEnd(T Value)
	{
		if (_Head == NULL)
		{
			_Head = new Node(Value, NULL, NULL);
			this->_Size++;

			return;
		}

		Node* Current = _Head;
		while (Current->Next != NULL)
			Current = Current->Next;

		this->_InsertAfter(Current, Value);
		this->_Size++;
	}


	// Find
	Node* Find(T Value) // Find The Node By Value
	{
		if (_Head == NULL || _Head->Value == Value)
			return _Head;

		Node* Current = _Head->Next;
		while (Current != NULL)
		{
			if (Current->Value == Value)
				return Current;

			Current = Current->Next;
		}

		return NULL;
	}


	// Delete
	void Delete(T Value)
	{
		if (_Head == NULL)
			return;
		Node* Current = _Head;

		if (Current->Value == Value)
		{
			if (Current->Next != NULL)
				Current->Next->Prev = NULL;
			_Head = Current->Next;

			delete Current;
			this->_Size--;

			return;
		}


		while (Current != NULL && Current->Value != Value)
			Current = Current->Next;

		if (Current == NULL)
			return;

		if (Current->Next != NULL)
			Current->Next->Prev = Current->Prev;
		if (Current->Prev != NULL)
			Current->Prev->Next = Current->Next;

		delete Current;
		this->_Size--;
	}

	void DeleteFirstNode()
	{
		if (_Head == NULL)
			return;

		Node* Temp = _Head;
		_Head = _Head->Next;

		if (_Head != NULL)
			_Head->Prev = NULL;

		delete Temp;
		this->_Size--;
	}

	void DeleteLastnode()
	{
		if (_Head == NULL)
			return;

		if (_Head->Next == NULL)
		{
			delete _Head;

			_Head = NULL;
			this->_Size--;

			return;
		}

		Node* Current = _Head->Next;
		while (Current->Next != NULL)
			Current = Current->Next;

		Current->Prev->Next = NULL;

		delete Current;
		this->_Size--;
	}

	void Clear()
	{
		while (this->Size > 0)
			this->DeleteFirstNode();
	}


	// Util
	void Print()
	{
		Node* Current = _Head;

		while (Current != NULL)
		{
			cout << Current->Value << " ";

			Current = Current->Next;
		}

		cout << endl;
	}

	void Reverse()
	{
		Node* Current = _Head;
		Node* Temp = NULL;

		while (Current != NULL)
		{
			Temp = Current->Prev;
			Current->Prev = Current->Next;
			Current->Next = Temp;

			Current = Current->Prev;
		}

		if (Temp != NULL)
			_Head = Temp->Prev;
	}
};
