#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
	int data;
	Node *next;
};

Node *top;

void push(int data)
{
	Node *newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = top->next;
	top->next = newNode;
}

void pop()
{
	Node *popNode = top->next;
	top->next = popNode->next;

	printf("You just popped: %d\n", popNode->data);
	free(popNode);
}

void display()
{
	Node *nextNode = top->next;

	printf("Elements in your stack: ");
	while(nextNode != NULL)
	{
		printf("%d ", nextNode->data);
		nextNode = nextNode->next;
	}
	printf("\n");
}

int main()
{
	top = malloc(sizeof(Node));
	top->next = NULL;
	
	push(1);
	push(3);
	push(4);
	push(5);
	pop();
	display();

	return 0;
}
