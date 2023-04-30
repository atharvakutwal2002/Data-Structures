#include <bits/stdc++.h>
using namespace std;

class DisJointSet
{
    vector<int> parent, rank ,size;

public:
    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUparent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findUparent(parent[node]);
    }

    void UnionBbyRank(int u, int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUparent(u); 
        int ulp_v = findUparent(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

int main()
{
    DisJointSet ds(7);
    ds.UnionBbyRank(1,2);
    ds.UnionBbyRank(2,3);
    ds.UnionBbyRank(4,5);
    ds.UnionBbyRank(6,7);
    ds.UnionBbyRank(5,6);

    if(ds.findUparent(3)==ds.findUparent(7)){
        cout<<"same "<<endl;
    }else{
        cout<<"Not same"<<endl;
    }

    ds.UnionBbyRank(3,7);

    if(ds.findUparent(3)==ds.findUparent(7)){
        cout<<"same "<<endl;
    }else{
        cout<<"Not same"<<endl;
    }

    return 0;
}