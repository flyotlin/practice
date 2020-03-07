#include <iostream>
#define MAX_ITEM 5

using namespace std;

//int MAX_ITEM = 5;
typedef struct tagStack {
    int data[MAX_ITEM];
    int top = -1;
} Stack;

Stack stk1;

void menu();
void push(Stack*);
void pop(Stack*);
void print_stack(Stack*);
int main()
{
    menu();
    return 0;
}

void menu() {
    int choice;
    cout << "1. Push\n2. Pop\n3. Print Stack\nYour Choice: ";
    cin >> choice;
    switch(choice) {
        case 1:
            push(&stk1);
            break;
        case 2:
            pop(&stk1);
            break;
        case 3:
            print_stack(&stk1);
            break;
    }
}
void push(Stack *stk) {
    int num;
    cout << "Enter the element you want to push: ";
    cin >> num;
    if(stk->top != MAX_ITEM-1) {
        stk->top++;
        stk->data[stk->top] = num;
    }
    menu();
}
void pop(Stack *stk) {
    if(stk->top != -1) {
        stk->top--;
    }
    menu();
}
void print_stack(Stack *stk) {
    if(stk->top == -1) {
        cout << "The Stack is empty now." << endl;
        menu();
    }
    cout << "The elements in Stack(From bottom to top): ";
    for(int i = 0; i <= stk->top; i++) {
        cout << stk->data[i] << " ";
    }
    cout << endl;
    menu();
}
