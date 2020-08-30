#include <stdio.h>
#include <stdlib.h>
#define NULL 0

typedef struct Node Node;

struct Node
{
    int data;
    Node *next;
};

Node *head;

void insertElement(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
}

void delete()
{
    Node *deleteNode = head->next;
    head->next = deleteNode->next;
    free(deleteNode);
}

void deleteElement(int data)
{
    Node *prevNode = head;
    Node *nextNode = head->next;
    while(nextNode != NULL)
    {
        if(nextNode->data == data)
        {
            prevNode->next = nextNode->next;
            free(nextNode);
            break;
        }
        prevNode = nextNode;
        nextNode = nextNode->next;
    }
}

void display()
{
    Node *nextNode = head->next;
    while(nextNode != NULL)
    {
        printf("%d ", nextNode->data);
        nextNode = nextNode->next;
    }
    printf("\n");
}

void testDrive()
{
    insertElement(4);
    insertElement(3);
    insertElement(2);
    insertElement(1);
    insertElement(0);
    delete();
    display();
    deleteElement(2);
    deleteElement(20);
    display();
}

int main()
{
    head = malloc(sizeof(Node));
    head->next = NULL;
    testDrive();
    return 0;
}
