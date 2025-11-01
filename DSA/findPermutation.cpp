
//https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
class Solution {
  public:
  
  
    void solve(string &s , vector<string>&ans,int i){
        if(i>=s.length()){
            ans.push_back(s);
            return;
        }
        unordered_set<char>st;
        for(int j=i; j<s.length(); j++){
            if(st.count(s[j])) continue;
            st.insert(s[j]);
            
            swap(s[i],s[j]);
            solve(s,ans,i+1);
            swap(s[i],s[j]);
        }
    }
  
    vector<string> findPermutation(string &s) {
        vector<string>ans;
        
        solve(s,ans,0);
        
        return ans;
    }
};
