#include <bits/stdc++.h>
using namespace std;

int mD(string s1, int m, string s2, int n)
{
    if (m == 0)
    {
        return n;
    }
    if (n == 0)
    {
        return m;
    }

    if (s1[m - 1] == s2[n - 1])
    {
        return mD(s1, m - 1, s2, n - 1);
    }
    int insert = mD(s1, m, s2, n - 1);
    int del = mD(s1, m - 1, s2, n);
    int replace = mD(s1, m - 1, s2, n - 1);
    return 1 + min(insert, min(del, replace));
}
