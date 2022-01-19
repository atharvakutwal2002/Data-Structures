#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates (int *arr,int n){
    vector <int> output;
    unordered_map<int, bool> mymap;
    for (int i = 0; i < n; i++)
    {
        if (mymap.count(arr[i])==0)
        {
            output.push_back(arr[i]);
            mymap[arr[i]]=true;
        }
        
    }
    return output;
}

int main(){
    int a[]={1,2,3,4,4,3,5,1,1,2};
    vector<int> output=removeDuplicates(a,10);
    for (int i = 0; i < output.size(); i++)
    {
        cout<< output[i]<<" ";
    }
    
}