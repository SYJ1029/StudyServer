#pragma once

#include <mutex>

template<typename T>
class LockStack
{
public:
	LockStack() {}

	LockStack(const Lockstack&) = delete;
	LockStack& operator=(const Lockstack&) = delete;

	void Push(T value)
	{
		lock_guard<mutex> lock(_mutex);
		_stack.push(std::move(value));
	}

	bool TryPop(T& value)
	{
		lock_guard<mutex> lock(_mutex);

		if (_stack.empty())
			return false;
		value = std::move(_stack.top());
		_stack.pop();
		return true;
	}

	void Pop()
	{

	}

private:
	stack<T> _stack;
	mutex _mutex;
	condition_variable _condVal;
};


