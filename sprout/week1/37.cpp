#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> Q;
    int t;
    cin >> t;
    while(t--) {
        int c;
        cin >> c;
        if(c == 1) {
            int num;
            cin >> num;
            Q.push(num);
        }
        else if(c == 2) {
            if(Q.empty())
                cout << "empty!" << endl;
            else {
                cout << Q.front() << endl;
                Q.pop();
            }
        }
    }
    return 0;
}
