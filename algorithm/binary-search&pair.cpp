#include <iostream>
#include <algorithm>
#include <utility>
#define N 1000005
#define endl '\n'
using namespace std;

pair<int, int> d[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q, want;
    cin >> n;   //知道pair要從0~n-1排序 後面沒用到的不用理會
    for(int i = 0; i < n; i++) {
        cin >> d[i].first;
        d[i].second = i;  //位置從0開始排列
    }
    sort(d, d+n);   //排序從0~n-1

    cin >> q;   //q次query
    while(q--) {
        cin >> want;
        int l = 0, r = n-1, mid;
        bool has = false;
        while(l <= r) {
            mid = (l+r)/2;
            if(d[mid].first == want) {
                cout << d[mid].second+1 << endl;
                has = true;
                break;
            }
            else if(d[mid].first < want)
                l = mid+1;
            else
                r = mid-1;
        }
        if(!has)
            cout << -1 << endl;
    }
    return 0;
}