#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1000005;  // maximum 1000 vertex
vector<int> G[maxn];    // graph
bool visit[maxn] = {};   // if visited
bool aRing = false;

void dfs(int u, int prev) {
    visit[u] = true;
    for(int i = 0; i < G[u].size(); i++) {
        if(visit[G[u][i]] == true && G[u][i] != prev) {    //remember從哪來
            aRing = true;
        }
        else if(visit[G[u][i]] == false) {
            dfs(G[u][i], u);
        }
    }
}

void add_undirected_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}
int main()
{
    /*
     * Directed Graph
     */
    int t;
    cin >> t;
    while(t--) {
        int uu, vv;
        cin >> uu >> vv;
        add_undirected_edge(uu, vv);
    }

    dfs(1, 1);
    if(aRing == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}