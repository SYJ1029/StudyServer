#pragma once

#include <mutex>

template<typename T>
class LockStack
{
public:
	LockStack() {}

	LockStack(const LockStack&) = delete;
	LockStack& operator=(const LockStack&) = delete;

	void Push(T value)
	{
		lock_guard<mutex> lock(_mutex);
		_stack.push(std::move(value));
		_condVar.notify_one();
	}

	bool TryPop(T& value)
	{
		lock_guard<mutex> lock(_mutex);
		if (_stack.empty())
			return false;

		// empty -> top -> pop
		value = std::move(_stack.top());
		_stack.pop();
		return true;
	}

	void WaitPop(T& value)
	{
		unique_lock<mutex> lock(_mutex);
		_condVar.wait(lock, [this] { return _stack.empty() == false; });
		value = std::move(_stack.top());
		_stack.pop();
	}

private:
	stack<T> _stack;
	mutex _mutex;
	condition_variable _condVar;
};

template<typename T>
class LockFreeStack {
	struct Node 
	{
		Node(const T& value) : data(value)
		{

		}

		T data;
		Node* next;
	};
public:

	void Push(const T& value)
	{
		Node* node = new Node(value);
		node->next = head;		

		while (_head.compare_exchange_weak(node->next, node) == false)
		{
		}
	}

	bool TryPop(T& value)
	{
		Node* oldhead = _head;
		_head = _head->next;
		value = oldhead->data;
		delete oldhead;

	}
private:
	std::atomic<Node*> _head;
};