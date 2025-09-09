#include "pch.h"
#include <iostream>
#include <windows.h>
#include "CorePch.h"

#include <thread>
#include <atomic>
#include <mutex>
#include <future>
#include <chrono>

#include "ConcurrentQueue.h"
#include "ConcurrentStack.h"

using namespace chrono_literals;

LockQueue<int32> q;
LockStack<int32> s;

void Push()
{
	while (true) 
	{
		int32 value = rand() % 100;
		q.Push(value);
		this_thread::sleep_for(10ms);
	}
}

void Pop()
{
	while (true)
	{


		int32 data = 0;
		if (q.TryPop(OUT data))
			cout << data << endl;

	}
}

int main()
{
	std::thread t1(Push);
	std::thread t2(Pop);
	std::thread t3(Pop);

	t1.join();
	t2.join();
	t3.join();
}