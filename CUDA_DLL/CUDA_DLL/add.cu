#include "add.cuh"


/**
* CUDA kernel
*/
__global__ void kernel(int* a, int* b, int* c) {

	int i = threadIdx.x;
	c[i] = a[i] + b[i];
}

/**
* Function adds two numbers and stores the result in c
*/
void addTwoNum(int* a, int* b, int* c) {

	int* d_a, * d_b, * d_c;

	cudaMalloc((void**)&d_a, sizeof(int));
	cudaMalloc((void**)&d_b, sizeof(int));
	cudaMalloc((void**)&d_c, sizeof(int));

	cudaMemcpy(d_a, a, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, b, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_c, c, sizeof(int), cudaMemcpyHostToDevice);

	kernel << <1, 1 >> > (d_a, d_b, d_c);

	cudaMemcpy(c, d_c, sizeof(int), cudaMemcpyDeviceToHost);

	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);
}