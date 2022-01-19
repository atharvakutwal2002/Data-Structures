#include<iostream>
using namespace std;

void printall(string input ,string output){
    if (input.length()==0)
    {
        cout<<output<<endl;
        return;
    }
    printall(input.substr(1),output+input[0]);
    printall(input.substr(1),output);
}

void printall2(char input[],char output[],int i){
    if (input[0]=='\0')
    {
        output[i]='\0';
        cout<<output<<endl;
        return;
    }
    printall2(input+1,output,i);

    output[i]=input[0];
    printall2(input+1,output,i+1);
}

int main(){

  char input[10];
  cin>>input;
  char output[100] ;

  string in;
  cin>>in;
  string out = "";

  printall(in, out);
  cout<<endl;

  printall2(input, output, 0);

  return 0;
}