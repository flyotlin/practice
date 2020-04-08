#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
int arr[20], num;   // num the max
vector<int> v;
void search(int n) {
    if(n == num) {
        return;
    }
    v.push_back(arr[n]);
    
    // print the vector
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    search(n+1);
    v.pop_back();
    search(n+1);

}
int main() {
    cin >> num;
    for(int i = 0; i < num; i++)
        cin >> arr[i];
    cout << endl;   // none
    search(0);
}