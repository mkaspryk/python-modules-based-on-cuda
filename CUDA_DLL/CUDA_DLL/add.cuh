#pragma once
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <stdio.h>

/**
*  CUDA kernel
*/
__global__ void kernel(int* a, int* b, int* c);

/**
* Function adds two numbers and stores it in c
*
*/
void addTwoNum(int* a, int* b, int* c);