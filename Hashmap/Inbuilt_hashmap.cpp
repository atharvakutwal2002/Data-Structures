#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> mymap;
    /// insertion of elements
    pair <string,int> p("abc",1);
    mymap.insert(p);
    mymap["def"]=2; //similar inserting as array 

    // accessing the elements
    cout<<mymap["abc"]<<endl;
    cout<<mymap.at("abc");

    // when we try to access the index which s not 
    cout<<mymap.at("ghi")<<endl; // will throw exception when 'ghi' index is not present 
    cout<<mymap["ghi"]<<endl; // this syntax will add 'ghi' index first and the value added corresponding to that index will be 0 

    ///check the presence of key
    if (mymap.count("ghi")>0)
    {
        cout<<"ghi is present"<<endl;
    }else{
        cout<<"not present"<<endl;
    }
    
    ///updating 
    mymap["abc"]=20;

    ///finding size
    cout<<"size "<<mymap.size()<<endl;

    ///erasing
    mymap.erase("ghi");


    return 0;
}