#include <iostream>
#include <queue>
#define NUM 1000105
#define N 1005
using namespace std;
int group[NUM]{};
int main()
{
    int n, k, c, t, wline = 1;
    while(cin >> n) {
        cout << "Line #" << wline++ << "\n";
        for(int i = 0; i < NUM; i++)    //把每個人編號清乾淨
            group[i] = -1;
        for(int i = 1; i <= n; i++) {   //輸入group資料 從1開始編排
            cin >> k;
            for(int j = 0; j < k; j++) {
                cin >> c;
                group[c] = i;
            }
        }
        queue<int> big_team;    //儲存整個隊伍
        queue<int> gg[N];    //儲存每一團隊的queue 1~n for 團客 200005 1005
        int g[N];    //隊伍是否在big_team中
        for(int i = 0; i < N; i++)
            g[i] = 0;
        string cmd;
        while(cin >> cmd && cmd != "STOP") {
            if(cmd == "ENQUEUE") {
                cin >> t;   //ENQUEUE哪個編號
                if(group[t] == -1) {    //陌生人
                    gg[0].push(t);
                    big_team.push(0);
                }
                else {  //團客
                    gg[group[t]].push(t);
                    if(g[group[t]] == 0) {
                        big_team.push(group[t]);
                        g[group[t]] = 1;
                    }
                }
            }
            else if(cmd == "DEQUEUE"){
                if(!big_team.empty()) {
                    int a = big_team.front();
                    cout << gg[a].front() << "\n";
                    gg[a].pop();
                    if(a == 0 || gg[a].empty())    //陌生人
                        big_team.pop();
                    if(gg[a].empty())
                        g[a] = 0;
                }
            }
        }
    }
    return 0;
}
