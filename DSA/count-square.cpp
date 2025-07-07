class Solution {
  public:
  
   
    
    int countSquares(int n) {
        // code here
        int ans = 0;
        for(int i=1; i*i<n; i++){
            
                ans++;
            }
        
        return ans;
    }
};
