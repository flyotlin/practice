#include <iostream>

using namespace std;

long long t[2][2] = {{1, 1}, {1, 0}}; // transform matrix
long long m[2][2] = {{1, 1}, {1, 0}};
void fast(long long exp) {
    if(exp == 1) {
        return;
    }
    else if(exp % 2 == 1) {
        fast(exp/2);
        // multiply m itself
        long long a = (m[0][0]*m[0][0] + m[0][1]*m[1][0]) % (1000000000 + 7);
        long long b = (m[0][0]*m[0][1] + m[0][1]*m[1][1]) % (1000000000 + 7);
        long long c = (m[1][0]*m[0][0] + m[1][1]*m[1][0]) % (1000000000 + 7);
        long long d = (m[1][0]*m[0][1] + m[1][1]*m[1][1]) % (1000000000 + 7);
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
        // multiply t
        a = (m[0][0]*t[0][0] + m[0][1]*t[1][0]) % (1000000000 + 7);
        b = (m[0][0]*t[0][1] + m[0][1]*t[1][1]) % (1000000000 + 7);
        c = (m[1][0]*t[0][0] + m[1][1]*t[1][0]) % (1000000000 + 7);
        d = (m[1][0]*t[0][1] + m[1][1]*t[1][1]) % (1000000000 + 7);
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }
    else {
        fast(exp/2);
        // multiply m itself
        long long a = (m[0][0]*m[0][0] + m[0][1]*m[1][0]) % (1000000000 + 7);
        long long b = (m[0][0]*m[0][1] + m[0][1]*m[1][1]) % (1000000000 + 7);
        long long c = (m[1][0]*m[0][0] + m[1][1]*m[1][0]) % (1000000000 + 7);
        long long d = (m[1][0]*m[0][1] + m[1][1]*m[1][1]) % (1000000000 + 7);
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }

}
int main()
{
    long long n;
    cin >> n;
    if(n == 0 || n == 1)
        cout << 1 << endl;
    else {
        fast(n-1);
        cout << (m[0][0] + m[0][1]) % (1000000000 + 7) << endl;
    }
    return 0;
}
