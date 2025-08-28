class Solution {
  public:
    int findSubarray(vector<int> &arr) {
       unordered_map<int,int>mp;
       mp[0] = 1;
       int ans = 0, sum = 0;
       for(int i=0; i<arr.size();i++){
           sum += arr[i];
           
           if(mp.count(sum)){
               ans += mp[sum];
           }
           
           mp[sum]++;
       }
       return ans;
    }
};
