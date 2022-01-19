#include <iostream>
using namespace std;
bool is_sorted(int a[], int n)
{
    //base case
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (a[0] > a[1])
    {
        return false;
    }

    //recursive case
    bool smallans = is_sorted(a + 1, n - 1);
    if (smallans)
    {
        return true;
    }
    else
    {
        return false;
    }
    /*the above step can also be written as 
        return smallans ;  */
}
int main()
{
    int a[] = {1, 2, 4, 3};
    // cout<<is_sorted(a,5);
    if (is_sorted(a, 4))
    {
        cout << "sorted";
    }
    else
    {
        cout << "Not sorted";
    }

    return 0;
}