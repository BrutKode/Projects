#include "stdio.h"
#include "stdlib.h"

typedef struct
{
	int value;
	struct node *next;
} node;

int main(void)
{
	node *Parent = malloc(sizeof(node));
	free(Parent);
	return 0;
}
