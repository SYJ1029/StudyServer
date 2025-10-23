#include "pch.h"
#include "Allocator.h"


void* BaseAllocator::Alloc(int32 size)
{
	void* ptr = malloc(size);
	return ptr;
}

void* BaseAllocator::Release(void* ptr)
{
	free(ptr);
	return nullptr;
}