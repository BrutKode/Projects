#include "../sort/bubble.h"
#include "../sort/print.h"

struct listItem {
	unsigned int index;
	struct listItem *next;
};

int main(void)
{
	unsigned int arr[] = {2,6,0,3,1,0,0,2,2,5,9,6};
	unsigned int const SIZE = std::size(arr);
	bubble(arr, SIZE);
	//print(arr, SIZE);
	
	unsigned int query = 0;
	unsigned int qcount{};
	listItem *parent = new listItem{};
	listItem *tmp = new listItem{};
	parent->next = tmp;
	for(int i{}; i<SIZE; ++i)
	{
		std::cout << "Iteration: " << i << std::endl;
		if(arr[i] == query)
		{
			listItem *moretmp = new listItem{};
			tmp->next = moretmp;
			tmp->index = i;
			tmp = moretmp;
			qcount += 1;
			if(arr[i+1] > query)
			{
				break;
			}
		}
	}

	std::cout << "Found: " << qcount << " Occurences of " << query << std::endl;
	std::cout << "RESULTS" << std::endl;
	tmp = parent->next;
	while(tmp->next != NULL)
	{
		listItem *moretmp = tmp;
		std::cout << "At Index: " << moretmp->index << std::endl;
		tmp = tmp->next;
		delete moretmp;
	}
	delete tmp;

	return 0;
}
