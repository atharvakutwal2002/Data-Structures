// #include<iostream>
// using namespace std;
// void remove(char a[],char b){
//     if ( a[0]=='\0')
//     {
//         return ;
//     }
//     if (a[0]!=b)
//     {
//         remove(a+1);
//     }
//     else 
//     {
//         for (int i = 0; a[i]!='\0'; i++)
//         {
//             a[i]=a[i+1];
//         }
//         remove(a);
//     }
   
// }
// int main(){
//     char a[]={'a','b','a','b'};
//     remove(a,'a');
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

void removeA(char input[]){
   if(input[0]=='\0'){
    return ;
   }
   if(input[0]!= 'a'){
    removeA(input + 1);
   }else{
      for(int i=0;input[i]!='\0';i++){
        input[i] = input[i+1];
      }
      removeA(input);
   }
}

int main(){
  char input[100];
  cin>>input;
  int l = length(input);
  cout<<l<<endl;
  cout<<input<<endl;

  removeA(input);

  cout<<length(input)<<endl;
  cout<<input<<endl;
  return 0;
}
