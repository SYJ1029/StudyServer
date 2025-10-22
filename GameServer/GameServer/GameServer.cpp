#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"

#include "RefCounting.h"

class Knight
{
public:
	Knight() 
	{
		std::cout << "Knight Created" << std::endl;
	}
	~Knight() 
	{
		std::cout << "Knight Destroyed" << std::endl;
	}

	static void* operator new(size_t size)
	{
		cout << "새로운 메모리 할당" << endl;

		void* ptr = malloc(size);

		return ptr;
	}

	static void operator delete(void* ptr)
	{
		cout << "메모리 제거" << endl;

		::free(ptr);
	}
};

// new도 오버로딩이 가능하다

//void* operator new(size_t size)
//{
//	cout << "새로운 메모리 할당" << endl;
//
//	void* ptr = malloc(size);
//
//	return ptr;
//}
//
//void operator delete(void* ptr)
//{
//	cout << "메모리 제거" << endl;
//
//	::free(ptr);
//}

int main()
{
	Knight* pKnight = new Knight();

	delete pKnight;
}

