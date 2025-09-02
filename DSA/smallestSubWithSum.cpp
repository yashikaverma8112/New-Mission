// https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
       int n = arr.size();
       int ans = INT_MAX;
       int sum = 0;
       
       int i =0;
       for(int j=0; j<n; j++){
           sum += arr[j];
           
           while(sum > x && i<=j){
               ans = min(ans, j-i+1);
               sum -= arr[i];
               i++;
           }
       }
       return ans==INT_MAX ? 0 : ans;
    }
};
