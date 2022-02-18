#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, int W, vector<int> price, vector<int> wts){
    if(n==0 || W==0){
        return 0;
    }
    
    if(wts[n-1] > W){
        return knapsack(n-1, W, price , wts);
    }else{
        int inc = price[n-1] + knapsack(n-1, W - wts[n-1], price, wts);
        int exl = knapsack(n-1 , W, price, wts);
        return max(inc,exl);
    }
}

int Solution::solve(vector<int> &price, vector<int> &wts, int W) {
    ///return knapsack(price.size(), W, price , wts);
    int n = price.size();
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else if(wts[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                int inc = price[i-1] + dp[i-1][j - wts[i-1]];
                int exl = dp[i-1][j];
                dp[i][j] = max(inc, exl);
            }
        }
    }
    return dp[n][W];
}
