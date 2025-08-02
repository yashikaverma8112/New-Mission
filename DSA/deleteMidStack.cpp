  void Delete(stack<int>& s ,int m){
        if(s.size()==m){
            s.pop();
            return;
            
        }
        int temp = s.top();
        s.pop();
        Delete(s,m);
        s.push(temp);
    }
    
    void deleteMid(stack<int>& s) {
       if(s.empty()) return;
       int m = (s.size()+1)/2;
       Delete(s,m);
    }
