#include<bits/stdc++.h>
using namespace std ;

void subsequence(vector<int> v ,int i ,vector<int> & ds){
    if(i >= v.size()){
        for (int i = 0; i < ds.size(); i++)
        {
            cout<<ds[i];
        }
        cout<<endl;
        
        return ;
    }
    ds.push_back(v[i]);
    subsequence(v, i+1 , ds);
    ds.pop_back();
    subsequence(v, i+1 , ds);
}

int main(){
    vector<int> v ={3,1,2};
    vector<int> ds ;
    subsequence(v , 0 , ds );

    return 0 ;
}