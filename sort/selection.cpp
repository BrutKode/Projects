#include "print.h"
#include "swap.h"

int main(void)
{
	std::cout << "Welcome to Selection Sort, Let's Sort this array: " << std::endl;
	unsigned int arr[] = {9,1,8,2,7,3,6,4,5,0};
	unsigned int const SIZE {std::size(arr)};
	print(arr,SIZE);

	int index{};
	for(size_t i{}; i<SIZE-1; ++i)
	{
		index = 0;
		for(size_t j{}; j<SIZE-i; ++j)
		{
			if(arr[j] > arr[index])
			{
				index = j;
			}
		}
		swap(arr[index], arr[SIZE-i-1]);
	}
	std::cout << "The sorted Array is: " << std::endl;

	print(arr,SIZE);
	return 0;
}
