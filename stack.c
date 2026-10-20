#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
	int value;
	struct node *next;
} node;

int main(void)
{
	node *Parent = malloc(sizeof(node));
	//Initial terminology
	node *Child = malloc(sizeof(node));
	Parent->next = Child;
	for(int i; i<100; ++i)
	{
		node *Grandchild = malloc(sizeof(node));
		Child->next = Grandchild;
		Grandchild->value = i;
		Child = Grandchild;
	}
	
	Child = Parent->next;
	for(int i; i<100; ++i)
	{
		node *Grandchild = Child->next;
		free(Child);
		Child = Grandchild;
	}

	free(Parent);
	return 0;
}
