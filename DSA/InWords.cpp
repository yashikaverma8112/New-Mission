// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    string arr[] = {"zero","one","two","three","four","five","six","seven", "eight", "nine"};
    if(n==0){
        return;
    }
    int rem = n%10;
    solve(n/10);
    cout<<arr[rem]<<" ";
}

int main() {
    int n ;
    cin>>n;
    
    cout<<"Print in Words"<<endl;
    solve(n);
    return 0;
}
