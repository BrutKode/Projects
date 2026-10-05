#include "print.h"
#include "swap.h"

struct linkedList {
	unsigned int *val{};
	struct linkedList *next{};
};

void createHalf(unsigned int *a, int count, bool isLeft, linkedList *tmp);
void iterate(unsigned int *a, int count, linkedList *tmp);

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

	linkedList *parent = new linkedList{};

	createHalf(arr,SIZE,true,parent); //Just work on the left half of parent array;
	createHalf(arr,SIZE,false,parent);

	print(arr, SIZE);

	linkedList *tmp = parent;
	while(tmp->next != NULL) {
		linkedList *moretmp = tmp;
		std::cout << moretmp->val << " at address " << moretmp << std::endl;
		tmp = tmp->next;
		delete moretmp;
	}

	return 0;
}

void createHalf(unsigned int *a, int count, bool isLeft, linkedList *tmp) {
	if(count % 2 == 0 && isLeft)
	{
		int val{count/2};
		unsigned int *b = new unsigned int[val];
		
		linkedList *newList = new linkedList{};
		tmp->next = newList;
		tmp->val = b;
		tmp = newList;

		for(int i{}; i<val; ++i)
		{
			b[i] = a[i];
		}
		iterate(b, val, tmp);
	}
	else if(count % 2 == 0)
	{
		int val{count/2};
		unsigned int *b = new unsigned int[val];

		linkedList *newList = new linkedList{};
                tmp->next = newList;
                tmp->val = b;
                tmp = newList;

                for(int i{}; i<val; ++i)
                {
                        b[i] = a[val+i];
                }
		iterate(b, val, tmp);
	}
        else if(isLeft)
        {
		int val{(count/2)+1};
		unsigned int *b = new unsigned int[val];

		linkedList *newList = new linkedList{};
                tmp->next = newList;
                tmp->val = b;
                tmp = newList;

                for(int i{}; i<val; ++i)
               	{
                	b[i] = a[i];
               	}
		iterate(b, val, tmp);
	}
	else
	{
		int val{count/2};
		unsigned int *b = new unsigned int[val];
		
		linkedList *newList = new linkedList{};
                tmp->next = newList;
                tmp->val = b;
                tmp = newList;

		for(int i{}; i<val; ++i)
		{
			b[i] = a[val+i+1];
		}
		iterate(b, val, tmp);
	}
}

void iterate(unsigned int *a, int count, linkedList *tmp) {
	if(count > 2)
        {
                print(a, count);
                createHalf(a, count, true, tmp); //Left
                createHalf(a, count, false, tmp); //Right
        }
        else
        {
		print(a, count);
                //std::cout << "Tree Exhausted!" << std::endl;
        }
}
