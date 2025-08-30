//https://www.geeksforgeeks.org/problems/smallest-factorial-number5929/1

class Solution {
  public:
    int findNum(int n) {
        /* TC - O(nlogn)

        int findNum(int n)
        {
        int dem1=0;  

         for(int i=5;i<=n*5;i=i+5) { 
             int i1=i; 
                 while(i1%5==0 ) {  
                     dem1++; 
                     i1=i1/5; 
                  if(dem1==n) return i;

                 }
         }
        }
*/


      // TC O(logn logn)
        int low = 0, high = 5*n, ans = -1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            int temp = mid, cnt = 0;
            
            while(temp > 0){
                temp /=5;
                cnt += temp;
            }
            if(cnt >= n){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
