#include "stdio.h"
#include "stdlib.h"

typedef struct {
	int num;
	//More properties can be added!
} element;

int main(void)
{
	//STATIC STACK
	/*
	 * Add Elements to stack
	 * Remove Elements from stack
	 * Copy elements of stack
	 */
	int top = -1;
	int SIZE;
	printf("Enter the number of elements desired to add to stack: "); //No need in dynamic stack implementation!
	scanf("%i", &SIZE);

	element *arr = calloc(SIZE, sizeof(element));

	

	free(arr);
	return 0;
}
