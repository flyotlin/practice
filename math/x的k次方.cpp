#include <iostream>

using namespace std;
const long long MOD = 1000000007;
long long fast(long long x, long long k) {
    if(k == 1) {
        return x % MOD;
    }
    if(k%2 == 1) {
        long long a = fast(x, k/2);
        return ((((a%MOD)*(a%MOD))%MOD)*x)%MOD;
    }
    else {
        long long a = fast(x, k/2);
        return ((a%MOD)*(a%MOD))%MOD;
    }
}
int main()
{
    long long x, k;
    cin >> x >> k;
    x %= MOD;
    if(k == 0)
        cout << 1 << endl;
    else {
        long long ans = fast(x, k);
        cout << ans%MOD << endl;
    }
    return 0;
}
