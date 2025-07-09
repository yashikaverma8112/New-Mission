class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        map<int,int>mp;
        vector<int>ans;
        for(int i=0; i<a.size(); i++){
            mp[a[i]]++;
        }
        for(int i=0; i<b.size(); i++){
            mp[b[i]]++;
        }
        
        for(auto itr=mp.begin(); itr!=mp.end();itr++){
            ans.push_back(itr->first);
        }
        
        return ans;
    }
};
