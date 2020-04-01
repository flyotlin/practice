#include <iostream>

using namespace std;
int num[100005];    //can be used repeatedly
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q, money, maximum = 2;
    cin >> n;
    int coin[n];
    for(int i = 0; i < n; i++) // input coin denomination
        cin >> coin[i];
    cin >> q;
    while(q--) {    // input quiry time
        cin >> money;
        int minl = 2147483647;
        num[0] = 0; num[1] = 1;
        for(int i = maximum; i <= money; i++) {
            for(int j = 0; j < n; j++) {
                if(i-coin[j] >= 0)
                    minl = min(minl, num[i-coin[j]]);
            }
            minl++;
            num[i] = minl;
        }
        cout << num[money] << "\n";
        maximum = max(maximum, money);
    }
    return 0;
}