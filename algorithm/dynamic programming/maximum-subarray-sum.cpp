#include <iostream>
#define N 1000005
#define endl '\n'

using namespace std;
typedef long long ll;
int arr[N];
int main()
{
    int n, mi = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] < 0)
            mi++;
    }
    if(mi == n) {
        cout << 0 << endl;
        return 0;
    }
    ll a, sum = 0, max = arr[0];
    for(int i = 0; i < n; i++) {
        a = sum + arr[i];
        if(a >= arr[i])
            sum = a;
        else
            sum = arr[i];

        if(sum > max)
            max = sum;
    }
    if(n == 0)
        cout << 0 << endl;
    else
        cout << max << endl;

    return 0;
}