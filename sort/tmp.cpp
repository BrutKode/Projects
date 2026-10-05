#include <iostream>

unsigned int const COUNT {1000};

struct list {
	int val{};
	struct list *next{};
};

int main(void)
{
	list *parent = new list{};
	list *tmp = new list{};
	parent->next = tmp;
	for(int i{}; i<COUNT; ++i)
	{
		list *newList = new list{};
		tmp->next = newList;
		tmp->val = i;

		tmp = newList;
	}
	
	tmp = parent;
	while(tmp->next != NULL) {
		list *moretmp = tmp;
		std::cout << moretmp->val << " at address " << moretmp << std::endl;
	       	tmp = tmp->next;
		delete moretmp;
	}
	delete tmp;

	return 0;
}
