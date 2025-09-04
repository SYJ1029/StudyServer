#include "pch.h"
#include <iostream>
#include "CorePch.h"

#include <thread>
#include <atomic>
#include <mutex>
#include <future>
#include <chrono>

using namespace chrono_literals;

queue<int32> q;
stack<int32> s;

void Push()
{
	while (true) 
	{
		int32 value = rand() % 100;
		q.push(value);

	}
}

void Pop()
{
	while (true) 
	{
		if (q.empty())
			continue;
		else
		{
			int32 data = q.front();
			q.pop();
			cout << data << endl;
		}
	}
}

int main()
{
	std::thread t1(Push);
	std::thread t2(Pop);
}