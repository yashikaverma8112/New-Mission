//https://leetcode.com/problems/binary-prefix-divisible-by-5/?envType=daily-question&envId=2025-11-24

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans;
        int val = 0;
        for(int i=0; i<nums.size();i++){
            val = ((val << 1 ) + nums[i]) % 5;
            ans.push_back(val==0);
        }
        return ans;
    }
};
