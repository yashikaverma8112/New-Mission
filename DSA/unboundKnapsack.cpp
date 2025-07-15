// User function Template for C++

class Solution {
    
  public:
    
    int solve(vector<pair<int, int>>& bag, int cap, int i, vector<vector<int>>& dp) {
        if (i == bag.size()) return 0;

        if (dp[i][cap] != -1) return dp[i][cap];

        int incl = 0;
        if (cap >= bag[i].second) {
            incl = bag[i].first + solve(bag, cap - bag[i].second, i, dp); // Unbounded: stay at i
        }

        int excl = solve(bag, cap, i + 1, dp); // Move to next item

        return dp[i][cap] = max(incl, excl);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<int, int>> bag;

        for (int i = 0; i < n; i++) {
            bag.push_back({val[i], wt[i]});
        }

        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

        return solve(bag, capacity, 0, dp);
    }
};
