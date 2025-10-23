#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"

#include "RefCounting.h"
#include "Memory.h"


class Knight
{
public:
	Knight() 
	{
		std::cout << "Knight Created" << std::endl;
	}

	Knight(int32 hp) : _hp(hp)
	{
		cout << "Knight(hp)" << endl;
	}

	~Knight() 
	{
		std::cout << "Knight Destroyed" << std::endl;
	}

	//static void* operator new(size_t size)
	//{
	//	cout << "새로운 메모리 할당" << endl;

	//	void* ptr = malloc(size);

	//	return ptr;
	//}

	//static void operator delete(void* ptr)
	//{
	//	cout << "메모리 제거" << endl;

	//	::free(ptr);
	//}

private:
	int32 _hp = 100;
	int32 _mp = 10;
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
	Knight* pKnight = xnew<Knight>(300);

	xdelete<Knight>(pKnight);
}

