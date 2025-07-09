 void rotate(vector<int> &arr) {
        // code here
        int n = arr.size();
        int lastEle = arr[n-1];
        
        int i = n-1;
        while(i>0){
            arr[i] = arr[i-1];
            i--;
        }
        arr[0]=lastEle;
    }
