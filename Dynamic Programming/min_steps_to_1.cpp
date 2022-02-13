#include <bits/stdc++.h>
using namespace std;

int minsteps(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    int x = minsteps(n - 1);

    int y=INT_MAX,z=INT_MAX;
    if (n % 2 == 0)
    {
         y = minsteps(n / 2);
    }
    if (n % 3 == 0)
    {
         z = minsteps(n / 3);
    }

    return min(x,min(y,z))+1;
}
int main()
{
    int n = 9;
    cout << minsteps(10);

    return 0;
}
