#include "swap.h"
#include "print.h"

#ifndef BUBBLE_H
#define BUBBLE_H

void bubble(unsigned int *a, unsigned int s) {
	for(int i{}; i<s-1; ++i) 
	{
		for(int j{}; j<s-i-1; ++j) 
		{
			if(a[j] > a[j+1]) 
			{
				swap(a[j], a[j+1]);
			}
		}
	}
	print(a,s);
}

#endif
