// https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1

class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int sum = 0;
        int n = arr.size();
        int l = 1;
        for(int i=0; i<arr.size();i++){
            sum += arr[i] * (l*n);
            l++;
            n--;
        }
        
        return sum;
    }
};
