#include <iostream>
const int N = 1000005;
using namespace std;
long long dp[N];
int main()
{
    dp[1] = 3;
    dp[2] = 7;
    int n;
    cin >> n;
    for(int i = 3; i <= n; i++) {
        dp[i] = (2*dp[i-1] + dp[i-2]) % 1000000007;
    }
    cout << dp[n] << endl;
    return 0;
}

