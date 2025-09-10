// https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        vector<int>ans;
        
        int s = 0;
        int e = 0;
        int sum = 0;
        for(int i=0; i<arr.size();i++){
            if(sum < target){
                sum += arr[i];
                e = i;
            }
            if(sum > target){
                while(sum > target){
                    sum -= arr[s];
                    s++;
                }
            }
            if(sum==target){
                ans.push_back(s+1);
                ans.push_back(e+1);
                return ans;
            }
        }
        return {-1};
    }
};
