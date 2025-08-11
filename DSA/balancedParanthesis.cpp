
class Solution {
  public:
    bool isBalanced(string& k) {
        // code here
        stack<char>st;
        
        for(int i=0; i<k.size();i++){
            if(k[i]=='(' || k[i]=='[' || k[i] == '{'){
                st.push(k[i]);
            }
            else if(!st.empty() && ((k[i]==')' && st.top()=='(')
            ||(k[i]==']' && st.top()=='[') || (k[i]=='}' && st.top()=='{')
            ) ){
                st.pop();
            }
            else{
                return false;
            }
        }
        
        if(!st.empty()){
            return false;
        }
        return true;
    }
};
