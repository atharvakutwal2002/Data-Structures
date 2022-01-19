#include<iostream>
using namespace std;

class stack{
    int *arr;
    int nextIndex;
    public:
        stack(){
            arr=new int[4];
            nextIndex=0;
        }
        stack(int cap){
            arr=new int[cap];
            nextIndex=0;
        }
        //return no.of elements in stack
        int size(){
            return nextIndex;
        }

        bool isempty(){
            // if(nextIndex==0){
            //     return true;
            // }else{
            //     return false;
            // }

            return nextIndex==0;
        }

        void push(int x){
            
        }



};

int main(){


    return 0;
}