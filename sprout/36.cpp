#include <iostream>

using namespace std;

typedef struct tagStack {
    int data;
    struct tagStack *next;
//    Stack *next;
} Stack;

void push(Stack*, int);
void pop(Stack*);
int main()
{
    Stack *head = new Stack;
    head->next = NULL;
    int t;
    cin >> t;
    while(t--) {
        int c;
        cin >> c;
        if(c == 1) {
            int num;
            cin >> num;
            push(head, num);
        }
        else if(c == 2)
            pop(head);
    }
    return 0;
}
void push(Stack *S, int n) {
    Stack *p = new Stack;
    p->next = S->next;
    p->data = n;
    S->next = p;
}

void pop(Stack *S) {
    if(S->next == NULL) {
        cout << "empty!" << endl;
        return;
    }
    Stack *p = S->next;
    cout << p->data << endl;
    S->next = p->next;
    delete p;
}
