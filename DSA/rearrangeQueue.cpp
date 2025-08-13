https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1

class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        // code here
        int size = q.size();
        queue<int>temp;
        
        for(int i=0; i<size/2; i++){
            temp.push(q.front());
            q.pop();
        }
        
        while(!q.empty() && !temp.empty()){
            q.push(temp.front());
            temp.pop();
            
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};
