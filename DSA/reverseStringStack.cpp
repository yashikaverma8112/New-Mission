class Solution {
  public:
    string reverse(const string& S) {
        // code here
        
        stack<char>s;
        
        for(int i=0; i<S.length(); i++){
            s.push(S[i]);
        }
        
        
        string ans = "";
        
        while(!s.empty()){
            
        
            char temp = s.top();
            s.pop();
            
            ans += temp;
        }
        
        return ans;
    }
};
