/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */


void solve(stack<int>&s, int x){
    if(s.empty() || x > s.top()){
        s.push(x);
        return;
    }
    
    int temp = s.top();
    s.pop();
    solve(s,x);
    s.push(temp);
}

void SortedStack ::sort() {
    
    if(!s.empty()){
        int x = s.top();
        s.pop();
        sort();
        
        solve(s,x);
    }
    
}
