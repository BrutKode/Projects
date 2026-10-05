#include <iostream>

struct Object 
{
	int id{};
	std::string secret{};
};

int main(void)
{
	std::string secret{};
	std::cout << "Enter Object secret: ";
	std::cin >> secret;
	Object* Person = new Object{};
	Person->id = 1;
	Person->secret = secret;
	std::cout << "Object created at " << Person << " with id " << Person->id << " and secret " << Person->secret << std::endl;
	delete Person;
	return 0;
}
