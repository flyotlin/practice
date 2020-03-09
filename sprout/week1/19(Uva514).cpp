#include <iostream>

using namespace std;

typedef struct tagStack {
    int data;
    struct tagStack *next;
} Stack;

bool test(Stack*, Stack*, int);
void push(Stack*, int);
int pop(Stack*);
int main()
{
    int t;
    cin >> t;
    while(t--) {
        Stack *btrack = new Stack;
        Stack *station = new Stack;
        btrack->next = NULL;
        station->next = NULL;
        int n;
        cin >> n;
        for(int i = n; i >= 1; i--)
            push(btrack, i);

        int atrack[n];
        for(int i = 0; i < n; i++)
            cin >> atrack[i];

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!test(btrack, station, atrack[i])) {
                cout << "No" << endl;
                break;
            }
            count++;
        }
        if(count == n)
            cout << "Yes" << endl;
    }
    return 0;
}
bool test(Stack* B, Stack *S, int num) {
    if(S->next != NULL) {
        Stack *p = S->next;
        int r = p->data;
        if(r == num) {
            pop(S);
            return true;
        }
    }
    int bpop = pop(B);
    while(num >= bpop) {
        if(bpop == num) {
            return true;
        }
        push(S, bpop);
        bpop = pop(B);
    }
    int spop = pop(S);
    if(spop == num)
        return true;
    return false;
}
void push(Stack *S, int n) {
    Stack *p = new Stack;
    p->data = n;
    p->next = S->next;
    S->next = p;
}
int pop(Stack *S) {
    if(S->next == NULL)
        return 2147483647;
    Stack *p = S->next;
    int re = p->data;
    S->next = p->next;
    delete p;
    return re;
}
