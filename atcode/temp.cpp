#include <iostream>

struct linkedList
{
	int val{};
	struct linkedList *next{NULL};
};

int main(void)
{
	std::cout << "This is a temporary file to check basics: " << std::endl;
	
	std::cout << "SHORT INT " << sizeof(short int) << "Bytes" << std::endl;
	std::cout << "INT " << sizeof(int) << "Bytes" << std::endl;
	std::cout << "LONG INT " << sizeof(long int) << "Bytes" << std::endl;
	std::cout << "LONG LONG INT " << sizeof(long long int) << "Bytes" << std::endl;
	
	//std::cout << "SHORT DOUBLE? " << sizeof(short double) << std::endl;
	std::cout << "DOUBLE " << sizeof(double) << "Bytes" << std::endl;
	std::cout << "LONG DOUBLE " << sizeof(long double) << "Bytes" << std::endl;
	//std::cout << "LONG LONG DOUBLE " << sizeof(long long double) << std::endl;
	
	std::cout << "BOOL " << sizeof(bool) << "Bytes" << std::endl;
	std::cout << "CHAR " << sizeof(char) << "Bytes" << std::endl;

	auto lFunc = [] () {
		std::cout << "Lambda Function is called! " << std::endl;
	};
	lFunc();
	
	unsigned int const RANGE{101};
	linkedList *parent = new linkedList();
	linkedList *nxt = parent;

	for(int i{}; i<RANGE; ++i)
	{
		linkedList *temp = new linkedList();
		temp->val = i;
		nxt->next = temp;
		nxt = temp;
	}

	nxt = parent->next;
	for(int i{}; i<RANGE; ++i)
	{
		std::cout << nxt->val << std::endl;
		nxt = nxt->next;
	}	

	nxt = parent;
	for(int i{}; i<RANGE; ++i)
	{
		linkedList *del = nxt;
		nxt = del->next;
		delete del;
	}
	delete nxt;
	
	return 0;
}
