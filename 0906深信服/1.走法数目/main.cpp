// 一个游戏玩家有k点体力,在一个m*n的表格中,其中k,m,m都为正整数,玩家位于(0,0),要到达终点(m,n).
// 玩家只能上下左右移动,且每次只能移动1的长度并消耗1体力,当体力耗尽时玩家无法移动
// 给定k,m,n问玩家能否移动到终点,如能,给出能到达终点的最短路径的走法数目

#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

int func(int k,int m,int n){
    if(k < m + n){
        return 0;
    }
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    dp[0][0] = 1;
    for(int i = 1;i <= m;++i){
        dp[i][0] = 1;
    }
    for(int j = 1;j <= n;++j){
        dp[0][j] = 1;
    }
    for(int i = 1;i <= m;++i){
        for(int j = 1;j <= n;++j){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m][n];
}

int func1(int k,int m,int n){
    if(k < m + n){
        return 0;
    }
    vector<int> dp(n+1,0);

    dp[0] = 1;
    for(int j = 1;j <= n;++j){
        dp[j] = 1;
    }
    for(int i = 1;i <= m;++i){
        dp[0] = 1;
        for(int j = 1;j <= n;++j){
            dp[j] = dp[j] + dp[j-1];
        }
    }
    return dp[n];
}

int main(){
    cout<<func1(4,1,1)<<endl;
}