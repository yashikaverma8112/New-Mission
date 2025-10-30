// https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

class Solution {
  public:
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        int n = s.length();
        
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(s[i]==s[j] && i!=j){
                    curr[j] = 1 + next[j+1];
                }
                else{
                    curr[j] = max(next[j],curr[j+1]);
                }
            }
            next = curr;
        }
        
        return next[0];
    }
};
