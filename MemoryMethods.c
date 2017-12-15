#include <sys/mman.h>
#include <stddef.h>

typedef struct {
	int *pointer;
	int reservedSpace;
} Variable;

int initMemory(int sizeOfRegion);
void *allocateMemory(int size);
int freeMemory(int *ptr);
int isMemoryValid(void *ptr);
int getMemorySize(void *ptr);

long ALLOCATED_SIZE = 0;
int* MAP_ADDRESS = 0;
Variable* VARIABLES;

int main()
{
	initMemory(30);
	return 0;
}

//Allocates the memory to be used by the methods below.
//Returns 0 on success, -1 on failure
int initMemory(int sizeOfRegion)
{
	
	int remainder = sizeOfRegion % getpagesize();
	
	//Makes the ALLOCATED_SIZE be divisible by pageSize
	//Therefore there aren't any partially allocated blocks.
	if (remainder == 0)
	{
		ALLOCATED_SIZE = sizeOfRegion;
	}
	else
	{
		ALLOCATED_SIZE = sizeOfRegion + getpagesize() - remainder;
	}
	
	//Get address map
	MAP_ADDRESS = mmap(NULL, sizeOfRegion, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	
	//return whether mem is available to you or not
	if(MAP_ADDRESS == MAP_FAILED) { 
		return -1;
	} else {
		return 0;
	}
}

//Allocates size amount of memory and returns a pointer to the start of the memory block
//Returns Pointer or Null if not enough free space
void *allocateMemory(int size)
{
	
}

//Frees memory if the pointer falls within an allocated block of memory
//returns 0 on success and -1 on failure
int freeMemory(int *ptr)
{
	return 0;
}

//Used in free memory.  Tells whether a pointer falls within an already allocated memory block
//Returns 1 if ptr falls in allocated block, 0 if it does not
int isMemoryValid(void *ptr)
{
	return 0;
}

//Used in allocateMemory to get the size of an allocated block
//returns the size in bytes of the memory block, otherwise -1
int getMemorySize(void *ptr)
{
	return 0;
}