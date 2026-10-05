#include "print.h"
#include "swap.h"

void createHalf(unsigned int *a, int count, bool isLeft);
void iterate(unsigned int *a, int count);

int main(void)
{
	unsigned int arr[] = {1,5,1,3,2,2,8,3,0};
	unsigned int const SIZE = std::size(arr);

	std::cout << "Welcome to Merge Sort, Let's Sort this array: " << std::endl;
	print(arr,SIZE);
	std::cout << std::endl;
	
	for(auto e : arr)
	{
		std::cout << e << " at " << &e << std::endl;
	}

	createHalf(arr,SIZE,true); //Just work on the left half of parent array;
	createHalf(arr,SIZE,false);

	print(arr, SIZE);

	return 0;
}

void createHalf(unsigned int *a, int count, bool isLeft) {
	if(count % 2 == 0 && isLeft)
	{
		int val{count/2};
		unsigned int b[val];
		for(int i{}; i<val; ++i)
		{
			b[i] = a[i];
		}
		iterate(b, val);
	}
	else if(count % 2 == 0)
	{
		int val{count/2};
                unsigned int b[val];
                for(int i{}; i<val; ++i)
                {
                        b[i] = a[val+i];
                }
		iterate(b, val);
	}
        else if(isLeft)
        {
		int val{(count/2)+1};
		unsigned int b[val];
                for(int i{}; i<val; ++i)
               	{
                	b[i] = a[i];
               	}
		iterate(b, val);
	}
	else
	{
		int val{count/2};
		unsigned int b[val];
		for(int i{}; i<val; ++i)
		{
			b[i] = a[val+i+1];
		}
		iterate(b, val);
	}
}

void iterate(unsigned int *a, int count) {
	if(count > 2)
        {
                print(a, count);
                createHalf(a, count, true); //Left
                createHalf(a, count, false); //Right
        }
        else
        {
		print(a, count);
                //std::cout << "Tree Exhausted!" << std::endl;
        }
}
