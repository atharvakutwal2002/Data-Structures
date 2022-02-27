#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> matrix, int sv)
{
    int n = matrix.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int cv = q.front();
        q.pop();
        cout << cv << endl;
        for (int i = 0; i < n; i++)
        {
            if (matrix[cv][i] && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i <= e; i++)
    {
        int fv, sv;
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }
    return 0;
}