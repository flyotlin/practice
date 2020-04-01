#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2000010;
typedef long long ll;
ll arr[N];
int main()
{
    int n;
    ll maxc=0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i != n-1)
            arr[n+i] = arr[i];
    }
    ll sum = 0;
    int len = 0;
    for(int i = 0; i < 2*n-1; i++) {
        len++;
        if(sum+arr[i] > arr[i]) {
            sum += arr[i];
        }
        else {
            sum = arr[i];
            len = 1;
        }
        maxc = max(maxc, sum);  // maxc != sum, then need to set len = 0
        if(len == n) {
            sum = arr[i];
            len = 1;
        }

    }
    cout << maxc << endl;
    return 0;
}