// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(),a.end());
        int i = 0;
        int j = m - 1;
        int ans = INT_MAX;
        while(j<a.size()){
            int diff = a[j] - a[i];
            ans = min(ans,diff);
            
            i++;
            j++;
        }
        return ans;
    }
};
