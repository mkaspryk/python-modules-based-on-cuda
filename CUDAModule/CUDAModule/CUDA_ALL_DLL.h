#ifdef CUDA_ALL_DLL_EXPORTS
#define CUDA_ALL_DLL_API __declspec(dllimport)
#else
#define  CUDA_ALL_DLL_API __declspec(dllexport)
#endif

/**
add two numbers function
*/
extern "C" CUDA_ALL_DLL_API void addTwoNumbers(int* a, int* b, int* c);