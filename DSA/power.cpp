int solve(int n,int power){
   if(power==0){
       return 1;
   }
   
   return n*solve(n,power-1);
}

int main() {
    int n,power ;
    cin>>n>>power;
    
    cout<<"Power"<<endl;
    cout<<solve(n,power);
    return 0;
