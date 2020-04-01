#include <iostream>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int arr[n], len[n], maxlen = 1;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        len[i] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] <= arr[i]) {
                len[i] = max(len[i], len[j]+1);
            }
        }
        maxlen = max(maxlen, len[i]);
    }
    cout << n-maxlen << endl;
    return 0;
}