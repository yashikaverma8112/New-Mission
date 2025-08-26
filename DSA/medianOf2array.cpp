class Solution {
  public:
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
};
