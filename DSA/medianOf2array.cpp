class Solution {
  public:
// TC - O((n+m) log(n+m))
    double medianOf2(vector<int>& a, vector<int>& b) {
            vector<int>temp(a);
            
            double median ;
            
            for(int i=0; i<b.size();i++){
                temp.push_back(b[i]);
            }
            
            sort(temp.begin(),temp.end());
            
            int n = temp.size();
            cout<<n<<" ";
            if(n%2){
                median = temp[(n+1)/2 -1];
                cout<<"odd";
            }
            else{
                median = (temp[n/2 -1] + temp[n/2])/2;
                cout<<"even";
            }
            return median;
    }

// TC - O(n+m)

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
      
      	// m1 to store the middle element
      	// m2 to store the second middle element
        int m1 = -1, m2 = -1;
    
        // loop till (m+n)/2
        for (int count = 0; count <= (m + n)/2; count++){
            m2 = m1;
          
         	// if both the arrays have remaining elements
            if (i != n && j != m)
                m1 = (a[i] > b[j]) ? b[j++] : a[i++];
            
          	// if only a[] has remaining elements
          	else if (i < n) 
                m1 = a[i++];
          
          	// if only b[] has remaining elements
            else 
                m1 = b[j++];
        }
    
        // return median based on odd/even size
        if ((m + n) % 2 == 1) 
            return m1;
        else
            return (m1 + m2) / 2.0;
    }
};
};
