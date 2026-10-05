#include "print.h"
#include "swap.h"

struct halfInfo
{
	unsigned int *b;
	unsigned int size;
	~halfInfo() {
		delete b;
	}
};

halfInfo* createLeftHalf(unsigned int *a, unsigned int s);
halfInfo* createRightHalf(unsigned int *a, unsigned int s);

int main(void)
{
	unsigned int arr[] = {2,6,0,3,1,0,0,2,2,5,9,6};
	unsigned int const SIZE = std::size(arr);

	std::cout << "Welcome to Merge Sort, Let's Sort this array: " << std::endl;
	print(arr,SIZE);
	std::cout << std::endl;
	
	for(int i{}; i<SIZE; ++i)
	{
		std::cout << arr[i] << " at address " << &arr[i] << std::endl;
	}
	
	unsigned int val{SIZE};
	halfInfo *leftTmp = new halfInfo{arr, SIZE};
	halfInfo *rightTmp = new halfInfo{arr, SIZE};
	while(val > 1)
	{
		leftTmp = createLeftHalf(leftTmp->b, leftTmp->size);
		print(leftTmp->b, leftTmp->size);
		//TODO
		rightTmp = createRightHalf(rightTmp->b, rightTmp->size);
		print(rightTmp->b, rightTmp->size);
		//TODO
		val = rightTmp->size;
		delete leftTmp;
		delete rightTmp;
	}
	return 0;
}

halfInfo* createLeftHalf(unsigned int *a, unsigned int s)
{
	unsigned int val{};
	if(s%2 == 0)
	{
		val = s/2;
	}
	else
	{
		val = s/2 + 1;
	}
	unsigned int *b = new unsigned int[val];
	for(int i{}; i<val; ++i)
	{
		b[i] = a[i];
	}
	halfInfo *half = new halfInfo{b, val};
	return half;
}

halfInfo* createRightHalf(unsigned int *a, unsigned int s)
{
	unsigned int *b = new unsigned int[s/2];
	if(s%2 == 0)
	{
		for(int i{}; i<s/2; ++i)
		{
			b[i] = a[s/2+i];
		}
	}
	else 
	{
		for(int i{}; i<s/2; ++i)
		{
			b[i] = a[s/2+i+1];
		}
	}
	halfInfo *half = new halfInfo{b, s/2};
	return half;
}
