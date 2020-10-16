#include <stdio.h>
#define MAX_INT_SIZE 1000

typedef struct {
    int item[MAX_INT_SIZE];
    int digits;
} BigInteger;

typedef struct {
    int item[MAX_INT_SIZE];
    int top;
} Stack;

void push();    // stack operation push
int pop();      // stack operation pop
void createBigInt(BigInteger *bigInt, Stack *s);    // create a data structure to store BigInt
void showBigInt(BigInteger *bigInt);                // print out the BigInt
BigInteger* split(BigInteger *bigInt, int start, int end);  // split the BigInt, karatsuba needs this
BigInteger* add(BigInteger *a, BigInteger *b);              // BigInt add
BigInteger* substract(BigInteger *a, BigInteger *b);        // BigInt substract
BigInteger* multiply(BigInteger *a, BigInteger *b);         // BigInt n squared multiply
BigInteger* power10(BigInteger *bigInt, int pow);           // BigInt left shift operation under radix 10
BigInteger* karatsuba(BigInteger *a, BigInteger *b);        // BigInt Karatsuba Algorithm

int main()
{
    char c;
    Stack s1, s2;
    s1.top = -1;
    s2.top = -1;

    printf("Enter Multiplicand: \n");
    do {
        c = getchar();
        if (c != '\n')
            push(&s1, c-48);
    } while (c != '\n');

    printf("Enter Multipliplier: \n");
    do {
        c = getchar();
        if (c != '\n')
            push(&s2, c-48);
    } while (c != '\n');
    BigInteger x, y;
    x.digits = 0, y.digits = 0;
    createBigInt(&x, &s1);
    createBigInt(&y, &s2);
    BigInteger *result = karatsuba(&x, &y);
    showBigInt(result);

    return 0;
}

void push(Stack *s, int num)
{
    if (s->top < MAX_INT_SIZE)
        s->item[++s->top] = num;
}

int pop(Stack *s)
{
    if (s->top >= 0)
        return s->item[s->top--];
}

void createBigInt(BigInteger *bigInt, Stack *s)
{
    while (s->top != -1) {
        bigInt->item[bigInt->digits++] = pop(s);
    }
    return &bigInt;
}

void showBigInt(BigInteger *bigInt)
{
    printf("Result: ");
    for (int i = bigInt->digits-1; i >= 0; i--)
        printf("%d", bigInt->item[i]);
    printf("\n");
}

BigInteger* split(BigInteger *bigInt, int start, int end)
{
    BigInteger *result = malloc(sizeof(BigInteger));
    result->digits = 0;
    int k = 0;
    for (int i = start; i <= end; i++) {
        result->item[k++] = bigInt->item[i];
        result->digits++;
    }
    return result;
}

BigInteger* add(BigInteger *a, BigInteger *b)
{
    BigInteger *result = malloc(sizeof(BigInteger));
    int size = (a->digits > b->digits) ? a->digits : b->digits;
    int carry = 0;
    for (int i = 0; i < size; i++) {
        int a_num = ((i+1) <= a->digits) ? a->item[i] : 0;
        int b_num = ((i+1) <= b->digits) ? b->item[i] : 0;
        int sum = a_num + b_num + carry;
        result->item[result->digits++] = sum%10;
        carry = sum / 10;
    }
    if (carry != 0)
        result->item[result->digits++] = carry;
    return result;
}

BigInteger* substract(BigInteger *a, BigInteger *b)
{
    BigInteger *result = malloc(sizeof(BigInteger));
    int size = (a->digits > b->digits) ? a->digits : b->digits;
    int borrow = 0;
    for (int i = 0; i < size; i++) {
        int a_num = ((i+1) <= a->digits) ? a->item[i] : 0;
        int b_num = ((i+1) <= b->digits) ? b->item[i] : 0;
        int diff = a_num - borrow - b_num;
        borrow = 0;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        result->item[result->digits++] = diff;
    }
    return result;
}

BigInteger* multiply(BigInteger *a, BigInteger *b)
{
    BigInteger *result = malloc(sizeof(BigInteger));
    result->digits = a->digits * 2;
    for (int i = 0; i < result->digits; i++)
        result->item[i] = 0;
    for (int i = 0; i < b->digits; i++) {
        int carry = 0, k = i;
        for (int j = 0; j < a->digits; j++) {
            int sum = b->item[i]*a->item[j] + carry + result->item[k];
            carry = sum / 10;
            sum = sum % 10;
            result->item[k++] = sum;
        }
        result->item[k++] += carry;
    }
    if (result->item[result->digits-1] == 0)
        result->digits--;
    return result;
}

BigInteger* power10(BigInteger *bigInt, int pow)
{
    BigInteger *result = malloc(sizeof(BigInteger));
    result->digits = bigInt->digits + pow;
    int k = 0;
    for (int i = 0; i < result->digits; i++) {
        if (i < pow)
            result->item[i] = 0;
        else
            result->item[i] = bigInt->item[k++];
    }
    return result;
}

BigInteger* karatsuba(BigInteger *a, BigInteger *b)
{
    int size = a->digits;
    BigInteger *m = split(a, size/2, size-1);
    BigInteger *n = split(a, 0, (size-1)/2);
    BigInteger *s = split(b, size/2, size-1);
    BigInteger *t = split(b, 0, (size-1)/2);
    // ms 10 ^ n
    BigInteger *p0_o = multiply(m, s);
    BigInteger *p0 = power10(p0_o, size);
    // nt
    BigInteger *p2 = multiply(n, t);
    // 
    BigInteger *mPs = add(m, n);
    BigInteger *nPt = add(s, t);
    BigInteger *msnt = multiply(mPs, nPt);
    BigInteger *d = substract(msnt, p0_o);
    BigInteger *e = substract(d, p2);
    BigInteger *p1 = power10(e, size/2);

    BigInteger *res1 = add(p0, p1);
    BigInteger *result = add(res1, p2);

    return result;
}
