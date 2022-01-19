// #include<iostream>
// using namespace std;
// void remove_double(char a[]){
//     if (a[0]=='\0')
//     {
//         return ;
//     }
//     if (a[0]!=a[1])
//     {
//         remove_double(a+1);
//     }else{
//         for (int i = 0; a[i]!='\0'; i++)
//         {
//             a[i]=a[i+1];
//         }
//         remove_double(a);
        
//     }
// }
// int main(){
//     char a[]={'a','a','b','a','a'};
//     remove_double(a);
//     cout<<a;
//     return 0;
// }

#include<iostream>
using namespace std;

int length(char input[]){
    if(input[0]=='\0'){
        return 0;
    }
    return 1 + length(input+1);;
}

void removeConsecutiveDuplicates(char input[]){
     if(input[0]=='\0'){
        return;
     }
     if(input[0] != input[1]){
        removeConsecutiveDuplicates(input + 1);
     }else{
        for(int i = 0;input[i]!='\0';i++){
            input[i] = input[i+1];
        }
        removeConsecutiveDuplicates(input);
     }
}

int main(){
  char input[100];
  cin>>input;
  int l = length(input);
  cout<<l<<endl;
  cout<<input<<endl;

  removeConsecutiveDuplicates(input);

  cout<<length(input)<<endl;
  cout<<input<<endl;
  return 0;
}
