#include <iostream>
#include <algorithm>
#include <utility>
#define N 100005
using namespace std;
int main()
{
//    pair<int, int> time[N];
    int n, maxinterval = 1, s, f;
    cin >> n;
    pair<int, int> time[n];
    for(int i = 0; i < n; i++)
        cin >> time[i].second >> time[i].first; //first:µ²§ô second:¶}©l
    sort(time, time+n); //in ascending order of earliest finish time
    f = time[0].first;
    for(int i = 1; i < n; i++) {
        s = time[i].second;
        if(s > f) {
            maxinterval++;
            f = time[i].first;
        }
    }
    cout << maxinterval << endl;

    return 0;
}