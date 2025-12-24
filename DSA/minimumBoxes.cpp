// https://leetcode.com/problems/apple-redistribution-into-boxes/?envType=daily-question&envId=2025-12-24

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int ans = 0;
        int sum = 0;
        for(int i=0; i<apple.size(); i++){
            sum += apple[i];
        }
        int greedy = 0;
        for(int i=capacity.size()-1; i>=0; i--){
            greedy += capacity[i];

            if(greedy >= sum){
                ans++;
                return ans;
            }
            ans++;
        }
        return ans;
    }
};
