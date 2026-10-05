#include "swap.h"
#include "print.h"

#ifndef SELECTION_H
#define SELECTION_H

void selection(unsigned int *a, unsigned int s) {
	int indexOfLargest{};
	for(int i{}; i<s-1; ++i) 
	{
		indexOfLargest = 0;
		for(int j{}; j<s-i; ++j) 
		{
			if(a[j] > a[indexOfLargest]) 
			{
				indexOfLargest = j;
			}
		}
		swap(a[indexOfLargest], a[s-i-1]);
	}
	print(a,s);
}

#endif
