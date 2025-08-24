class Solution {

  public:
   
  
    long long countTriplets(int n, long long sum, long long arr[]) {
        sort(arr,arr+n);
        long long cnt = 0;
        for(int i=0; i<n-2;i++){
            int start = i+1;
            int end = n-1;
            
            while(start<end){
                
                long target = arr[i] + arr[start] + arr[end];
                
                if(target < sum){
                   cnt += (end - start);
                   start++;
                }
                else{
                    end--;
                }
                
            }
        }
        return cnt;
    }
};
