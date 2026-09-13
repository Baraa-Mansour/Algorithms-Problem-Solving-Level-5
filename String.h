#pragma once
#include <string>
#include <stack>

class String
{
private:
	std::string _Value = "";
	std::stack<std::string> _UndoStack;
	std::stack<std::string> _RedoStack;

public:
	std::string GetValue() { return this->_Value; }
	void SetValue(std::string Value) 
	{
		_UndoStack.push(this->_Value);
		_RedoStack = std::stack<std::string>();
		this->_Value = Value; 
	}
	__declspec(property(get = GetValue, put = SetValue))std::string Value;

	void Undo()
	{
		if (_UndoStack.empty())
			return;

		_RedoStack.push(_Value);

		this->_Value = _UndoStack.top();
		_UndoStack.pop();
	}

	void Redo()
	{
		if (_RedoStack.empty())
			return;

		_UndoStack.push(_Value);
		this->_Value = _RedoStack.top();
		_RedoStack.pop();
	}
};
