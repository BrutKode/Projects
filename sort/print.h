#include <iostream>

#ifndef PRINT_H
#define PRINT_H

template <typename T> void print(T a, unsigned int s) {
	std::cout << "[";

        for(int i{}; i<s-1; ++i)
        {
                std::cout << a[i] << ", ";
        }
        std::cout << a[s-1] << "]" << std::endl;
}

#endif
