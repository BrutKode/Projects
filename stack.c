#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
	int value;
	struct node *next;
} node;

node* addItem(int value, node *parent);
node* removeItem(node *parent);

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
		printf("The top of the stack is: %p\n", addItem(i, Parent));
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
		printf("The top of the stack is: %p\n", removeItem(Parent));
	}
	
	free(Child);
	free(Parent);
	return 0;
}

node* addItem(int value, node *parent)
{
	node *child = parent;
	if(parent->next != NULL)
	{
		child = parent->next;
		while(child->next != NULL)
		{
			child = child->next;
		}
	}
	node *grandchild = malloc(sizeof(node));
	child->next = grandchild;
	grandchild->value = value;
	grandchild->next = NULL;
	return grandchild;
}

node* removeItem(node *parent)
{
	node *child = parent->next;
	node *grandchild = child->next;
	if(child == NULL)
	{
		return NULL;
	}
	else if(child->next == NULL)
	{
		free(child);
		parent->next = NULL;
		return parent;
	}
	else
	{
		while(grandchild->next != NULL)
		{
			child = child->next;
			grandchild = grandchild->next;
		}
		free(grandchild);
		child->next = NULL;
		return child;
	}
}
