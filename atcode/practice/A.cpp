#include <iostream>

int main(void)
{
	int a{};
	int b{};
	int c{};
	std::string s{};
	std::cin >> a;
	std::cin >> b >> c;
	std::cin >> s;
	std::cout << a + b + c << " " << s << std::endl;
	
	return 0;
}
