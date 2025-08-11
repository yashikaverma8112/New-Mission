void push(stack<int>& s, int a){
// Your code goes here
    s.push(a);
    return;
}
 
bool isFull(stack<int>& s,int n){
// Your code goes here
    return s.size()==n;
    
}
 
bool isEmpty(stack<int>& s){
// Your code goes here
    return s.size()==0;
    
}
 
int pop(stack<int>& s){
// Your code goes here
    int x=s.top();
    s.pop();
    return x;
    
}
 
int fun(stack<int> s){
    int mini=1e9;
    while(!s.empty()){
        mini=min(mini,s.top());
        s.pop();
    }
    return mini;
    
} 
 
int getMin(stack<int>& s){
// Your code goes here
    return fun(s);
    
}
