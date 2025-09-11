
// https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
class Solution {
  public:
    
   static bool comp(int a, int b){
       string first = to_string(a);
       string second = to_string(b);
        if(first+second > second + first){
            return true;
        }
        else{
            return false;
        }
    }
  
    string findLargest(vector<int> &arr) {
       sort(arr.begin(),arr.end(),comp);
       string ans = "";
       if (arr[0] == 0) return "0";
       for(auto it:arr){
       
           ans += to_string(it);
           
       }
       return ans;
    }
};
