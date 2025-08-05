class Solution {
  public:
    vector<int>nextSmallerElement(vector<int>arr,int n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i = n-1;i>=0;i--){
            int curr = arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmallerElement(vector<int>arr,int n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i = 0;i<n;i++){
            int curr = arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<int>next = nextSmallerElement(arr,n);
        vector<int>prev = prevSmallerElement(arr,n);
        int area = INT_MIN;
        for(int i =0;i<n;i++){
            int l = arr[i];
            // next = nextSmallerElement(arr,n);
            // prev = prevSmallerElement(arr,n);
            
            if(next[i]==-1){
                next[i] = n;
            }
            int b = next[i]-prev[i]-1;
            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
};
