#include <iostream>

using namespace std;
typedef long long ll;
long long change(long long);
int main()
{
    ll n;
    ll total = 0;
    cin >> n;

//    for(int i = 0; i < 4; i++)
    total = change(n);
    cout << total << endl;
    return 0;
}
ll change(ll n) {
    ll t = 0;
    t += n / 50;
    n %= 50;
    t += n / 10;
    n %= 10;
    t += n / 5;
    n %= 5;
    t += n / 1;
    n %= 1;
    return t;
}