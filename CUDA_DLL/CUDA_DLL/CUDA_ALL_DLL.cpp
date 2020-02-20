#include "pch.h"
#include "framework.h"
#include "CUDA_ALL_DLL.h"
#include "add.cuh"

extern "C" CUDA_ALL_DLL_API void addTwoNumbers(int* a, int* b, int* c) {
	
	addTwoNum(a, b, c);
}