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
        for(int i = 0; i < NUM; i++)    //��C�ӤH�s���M���b
            group[i] = -1;
        for(int i = 1; i <= n; i++) {   //��Jgroup��� �q1�}�l�s��
            cin >> k;
            for(int j = 0; j < k; j++) {
                cin >> c;
                group[c] = i;
            }
        }
        queue<int> big_team;    //�x�s��Ӷ���
        queue<int> gg[N];    //�x�s�C�@�ζ���queue 1~n for �Ϋ� 200005 1005
        int g[N];    //����O�_�bbig_team��
        for(int i = 0; i < N; i++)
            g[i] = 0;
        string cmd;
        while(cin >> cmd && cmd != "STOP") {
            if(cmd == "ENQUEUE") {
                cin >> t;   //ENQUEUE���ӽs��
                if(group[t] == -1) {    //���ͤH
                    gg[0].push(t);
                    big_team.push(0);
                }
                else {  //�Ϋ�
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
                    if(a == 0 || gg[a].empty())    //���ͤH
                        big_team.pop();
                    if(gg[a].empty())
                        g[a] = 0;
                }
            }
        }
    }
    return 0;
}
