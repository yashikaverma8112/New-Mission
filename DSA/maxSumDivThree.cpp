class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
       int sum = 0;
       vector<int>mod1, mod2;

       for(int x:nums){
            sum += x;
            if(x%3==1) mod1.push_back(x);
            if(x%3==2) mod2.push_back(x);
       } 
       sort(mod1.begin(),mod1.end());
       sort(mod2.begin(),mod2.end());

       if(sum % 3==0){
            return sum;
       }
       int ans = INT_MIN;
       if(sum%3==1){
         if(!mod1.empty()){
            ans = max(ans,sum - mod1[0]);
         }
         if(mod2.size() >= 2){
            ans = max(ans, sum-mod2[0]-mod2[1]);
         }
       }
       else{
         if(!mod2.empty()){
            ans = max(ans,sum-mod2[0]);
         }
         if(mod1.size() >= 2){
            ans = max(ans,sum-mod1[0]-mod1[1]);
         }
       }
       return ans;
    }
};
