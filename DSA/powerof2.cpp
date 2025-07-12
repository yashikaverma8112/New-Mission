// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int solve(int power){
   if(power==0){
       return 1;
   }
   
   int reducePower = solve(power/2);
   
   if(power&1){
       return 2*reducePower*reducePower;
   }
   else{
       return reducePower*reducePower;
   }
}

int main() {
    int power ;
    cin>>power;
    
    cout<<"Power of 2"<<endl;
    cout<<solve(power);
    return 0;
}
