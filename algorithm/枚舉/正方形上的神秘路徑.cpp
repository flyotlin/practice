#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int square[14][14];
void traversal(vector<int> v, int i, int j) {
    v.push_back(square[i][j]);
    if(square[i][j+1] == -1 && square[i+1][j] == -1) {
        for(int ii = 0; ii < v.size(); ii++)
            cout << v[ii] << " ";
        cout << endl;
    }
    if(square[i][j+1] != -1)
        traversal(v, i, j+1);
    if(square[i+1][j] != -1) 
        traversal(v, i+1, j);
}
int main() {
    int n, count=1;
    cin >> n;
    for(int i = 0; i < 14; i++) {
        for(int j = 0; j < 14; j++) {
            square[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            square[i][j] = count;
            count++;
        }
    }
    vector<int> vv;
    traversal(vv, 0, 0);
}
