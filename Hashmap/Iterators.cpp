#include<bits/stdc++.h>
using namespace std;


int main(){
    unordered_map<string,int> mymap;
    mymap ["abc"]=1;
    mymap ["abc1"]=2;
    mymap ["abc2"]=3;
    mymap ["abc3"]=4;
    mymap ["abc4"]=5;
    mymap ["abc5"]=6;
//it is pair of k,v it->first is key and it->second is value 
    for ( unordered_map<string,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
    {    //another syntax ==>> auto it =mymap.begin();
        cout<<"key :"<<it->first<<" value : "<<it->second<<endl;
    }
// as it is ordered map so keys are sorted 
    map<string,int> mymap2;
    mymap2 ["abc"]=1;
    mymap2 ["abc1"]=2;
    mymap2 ["abc2"]=3;
    mymap2 ["abc3"]=4;
    mymap2 ["abc4"]=5;
    mymap2 ["abc5"]=6;
//it is pair of k,v it->first is key and it->second is value 
    for ( map<string,int>::iterator it1=mymap2.begin(); it1!=mymap2.end(); it1++)
    {
        cout<<"key :"<<it1->first<<" value : "<<it1->second<<endl;
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for (vector <int>:: iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
        /// here we have to write *it (de-referencing operator)
    }



    unordered_map<string,int>::iterator it=mymap.find("abc");
    mymap.erase(it);
    mymap.erase(mymap.begin(),mymap.end());
    ///find
    if (mymap.find("abc")==mymap.end())
    {
        cout<<"not present"<<endl;
    }else{
        cout<<"present"<<endl;
    }
    
    cout<<"size : "<<mymap.size();

    return 0;
}