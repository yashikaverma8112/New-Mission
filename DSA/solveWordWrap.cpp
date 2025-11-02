// https://www.geeksforgeeks.org/problems/word-wrap1646/1

class Solution {
  public:
    int solveWordWrap(vector<int> arr, int k) {
        int n = arr.size();
        int inf = 1e9+7;
        vector<int>v(n+1,inf);
         v[n]=0;
         for(int i=n-1; i>=0; i--){
             int ln=0;
             for(int j=i; j<n; j++){
                 ln+=arr[j];
                 if(j>i) ln++;
                 if(k-ln<0) break;
                 
                 int cost =0; 
                 if(j!=n-1){
                     cost = v[j+1]+(k-ln)*(k-ln);
                 }
                 
                 v[i] = min(v[i],cost );
             }
         }
        
        
        return v[0];
    }   
};
