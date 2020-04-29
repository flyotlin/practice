/**
 * 01knapsack problem(dp)
 * 狀態: dp(m, n) 空間為m時 從第0個物品到第n個物品 選擇放或者不放
 * 轉移式: dp(m, n)=max(dp(m, n-1), dp(m-第n個物品所占空間, n-1)+第n個物品的價值)
 * 前者為不放第n個的狀況 後者為放第n個的狀況
 * 
 * item從0開始編號
 * 我這次dp index n=0為第一項物品
 * 一般dp index n=0會設為沒有物品
 * 也因為這次n=0設為第一項物品
 * 所以第50行需要另外寫特例判
 * 也就是沒有物品的時候的狀況
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int item[n][2];   // 從0開始編號物品
    int dp[m+1][n];  // 定義狀態dp(m, i) i可以為0嗎?(假設物品從1編號)
    // 輸入物品體積以及價值
    for(int i = 0; i < n; i++) {
        cin >> item[i][0] >> item[i][1];    // 0:體積 1:價值
    }
    // 初始化dp第一列都為0
    for(int i = 0; i < n; i++) {
        dp[0][i] = 0;
    }
    // 初始化dp第一行
    for(int i = 1; i < m+1; i++) {
        if(i-item[0][0] < 0)
            dp[i][0] = 0;
        else {
            dp[i][0] = item[0][1];
        }
    }
    for(int i = 1; i < m+1; i++) {
        for(int j = 1; j < n; j++) {
            if(i-item[j][0] < 0) {
                dp[i][j] = dp[i][j-1];
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-item[j][0]][j-1] + item[j][1]);
            }
        }
    }
    // 特例判斷
    if(n == 0)
        cout << 0 << endl;
    else
        cout << dp[m][n-1] << endl;
    return 0;
}