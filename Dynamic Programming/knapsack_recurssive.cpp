#include<bits/stdc++.h>
using namespace std;


int knapsack(int n, int W, vector<int> price, vector<int> wts)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (wts[n - 1] > W)
    {
        return knapsack(n - 1, W, price, wts);
    }
    else
    {
        int inc = price[n - 1] + knapsack(n - 1, W - wts[n - 1], price, wts);
        int exl = knapsack(n - 1, W, price, wts);
        return max(inc, exl);
    }
}

int Solution::solve(vector<int> &price, vector<int> &wts, int W)
{
    return knapsack(price.size(), W, price, wts);
}
