class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
        map<char,int>mp;
        queue<char>q;
        string ans = "";
        for(int i=0; i<s.size(); i++){
            q.push(s[i]);
            mp[s[i]]++;
            
            while(!q.empty() && mp[q.front()]>1){
                q.pop();
            }
            if(q.empty()){
                ans += "#";
            }
            else{
                ans += q.front();
            }
        }
        
        return ans;
    }
};
