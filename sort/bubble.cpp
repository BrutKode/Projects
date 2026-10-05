#include "swap.h"
#include "print.h"

int main(void)
{
	std::cout << "Welcome to Bubble Sort, Let's Sort this array: " << std::endl;
	unsigned int arr[]{6,5,7,4,8,3,9,2,0,1};
	unsigned int const SIZE {std::size(arr)};

	//std::cout << "Sizeof Array " << sizeof(arr) << "Bytes" << std::endl;
	//std::cout << "Elements in Array " << SIZE << std::endl;
	/* Returns a pointer to the first element
	 * std::cout << arr << std::endl;
	 */
	
	//Using Range based for loop to print elements of array
	print(arr,SIZE);
	for(size_t i{}; i< SIZE-1; i++)
	{
		for(size_t j{}; j<SIZE-i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}

	//Checking swap function
	/*
	int a{3};
	int b{4};
	std::cout << a << " " << b << std::endl;
	std::cout << "Swapping..." << std::endl;
	swap(a,b);
	std::cout << a << " " << b << std::endl;
	*/

	//std::cout << largest << std::endl;
	std::cout << "The sorted Array is: " << std::endl;
	print(arr,SIZE);
	return 0;
}
