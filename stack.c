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
	Parent->value = 10;
	node *Child = malloc(sizeof(node));
	Parent->next = Child;
	Child->value = 11;
	Child->next = NULL;
	printf("Parent created at %p with value %i pointing towards child %p \n", Parent, Parent->value, Parent->next);
	
	for(int i=0; i<10; ++i)
	{
		node *Grandchild = malloc(sizeof(node));
		Child->next = Grandchild;
		Grandchild->value = i;
		Grandchild->next = NULL;
		Child = Child->next;
	}	
	
	Child = Parent->next;
	for(int i=0; i<10; ++i)
	{
		printf("%i child at %p points to %i child at %p\n", i, Child, i+1, Child->next);
		Child = Child->next;
	}

	Child = Parent->next;
	for(int i=0; i<10; ++i)
	{
		node *Grandchild = Child->next;
		printf("Killed child at %p\n", Child);
		free(Child);
		Child = Grandchild;
	}
	
	free(Child);
	free(Parent);
	return 0;
}
