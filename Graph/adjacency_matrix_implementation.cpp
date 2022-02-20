#include <bits/stdc++.h>
using namespace std;

//static implementation 

int main()
{
    int adj[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j= 0; j < 10; j++)
        {
            adj[i][j]=0;
        }
        
    }
    adj[1][2]=1;
    adj[3][2]=1;
    adj[5][8]=1;
    adj[7][1]=1;

    int v1;
    int v2;
    cin>>v1>>v2;
    if (adj[v1][v2]==1)
    {
        cout<<"edges connected \n"; 
    }else{
        cout<<"not connected \n";
    }
    

    
    return 0;
}