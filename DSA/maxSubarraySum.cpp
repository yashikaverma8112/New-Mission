//https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/?envType=daily-question&envId=2025-11-27


class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        /*
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(maxi < sum && (j-i+1) % k==0){
                    maxi = max(sum,maxi);
                }
            }
        }
        */
        vector<long long>minPref(k,LLONG_MAX);
        long long pref = 0;
        long long ans = LLONG_MIN;

        minPref[0] = 0;
        for(int j=0; j<n; j++){
            pref += nums[j];
            int r = (j+1) %k;

            if(minPref[r]!=LLONG_MAX){
                ans = max(pref-minPref[r],ans);
            }
            minPref[r] = min(minPref[r],pref);
        }
        return ans;
    }
};
