#include <bits/stdc++.h>
using namespace std;

class Diagonal
{
private:
    int *A;
    int n;

public:
    Diagonal()
    {
        n = 2;
        A = new int[2];
    }
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~Diagonal()
    {
        delete[] A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
}

int Diagonal::Get(int i, int j)
{
    if (i == j)
    {
        return A[i - 1];
    }
    return 0;
}

void Diagonal ::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << A[i] << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    Diagonal d(4);

    d.Set(1,1,5);
    d.Set(2,2,8);
    d.Set(3,3,9);
    d.Set(4,4,12);

    d.Display();
    return 0;
}