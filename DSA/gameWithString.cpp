https://www.geeksforgeeks.org/problems/game-with-string4100/1

class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        map<char,int>mp;
        int res = 0;
        priority_queue<int>pq;
        
        for(int i=0; i<s.size();i++){
            mp[s[i]]++;
        }
        
        for(auto &it  : mp ){
            pq.push(it.second);
        }
        
        while(k-- > 0 && !pq.empty()){
            int top = pq.top();
            pq.pop();
            top--;
            if(top > 0){
                pq.push(top);
            }
        }
        
        while(!pq.empty()){
            int cnt = pq.top();
            pq.pop();
            
            res += cnt * cnt;
        }
        
        return res;
    }
};
