#include <iostream>

int main(void)
{
	std::string s;
	std::getline(std::cin,s);
	s.resize(3);
	int count{};
	for(auto e : s)
	{
		if(int(e) == 49)
		{
			++count;
		}
	}
	std::cout << count << std::endl;
	return 0;
}
