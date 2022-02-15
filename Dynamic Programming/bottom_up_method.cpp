#include<bits/stdc++.h>
using namespace std;

int minSteps3(int n){

   int *dp = new int[n+1];
   dp[0] = 0;
   dp[1] = 0;

   /// dp[i] = min steps needed to move from i->1  , ans = dp[n]

   for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + 1 ;

        if(i%2==0){
            dp[i] = min(dp[i],dp[i/2] + 1);
        }
        if(i%3==0){
            dp[i] = min(dp[i],dp[i/3] + 1);
        }
   }

   int ans = dp[n];
   delete []dp;
   return ans;


}


/*int minSteps3(int n){

   int *dp = new int[n+1];
   dp[0] = 0;
   dp[1] = 0;

   /// dp[i] = min steps needed to move from i->1  , ans = dp[n]

   for(int i=2;i<=n;i++){
        int x = dp[i-1];
        int y,z;
        y=z=INT_MAX;

        if(i%2==0){
            y = dp[i/2];
        }
        if(i%3==0){
            z = dp[i/3];
        }
        dp[i] = min(x,min(y,z)) + 1;
   }
   return dp[n];


}
*/

int helper(int n, int *ans){
    /// base case
    if(n <= 1){
        return 0;
    }
    /// check if output already exist
    if(ans[n] != -1){
        return ans[n];
    }

    /// recursive
    int x = helper(n-1,ans);
    int y,z;
    y=z=INT_MAX;

    if(n%2==0){
         y = helper(n/2,ans);
    }
    if(n%3==0){
         z = helper(n/3,ans);
    }
    /// calculate ans
    int output = min(x,min(y,z)) + 1;

    /// save ans for future use
    ans[n] = output;

    return output;

}

int minSteps2(int n){

    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    return helper(n,ans);
}


int minSteps(int n){
    /// base case
    if(n <= 1){
        return 0;
    }
    /// recursive
    int x = minSteps(n-1);
    int y,z;
    y=z=INT_MAX;

    if(n%2==0){
         y = minSteps(n/2);
    }
    if(n%3==0){
         z = minSteps(n/3);
    }
    /// calculate ans
    int ans = min(x,min(y,z)) + 1;
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<minSteps(n)<<endl;
    cout<<minSteps2(n)<<endl;
    cout<<minSteps3(n)<<endl;

    return 0;
}
