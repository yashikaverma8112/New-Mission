/*Complete the function below*/

class Solution {
  public:
  
    bool isPalindrome(int num){
        int temp = num;
        int rev = 0;
        while(temp != 0){
            int rem = temp % 10;
            rev = rev * 10 + rem; 
            
            temp /= 10;
             
        }
        
        if(rev==num){
            return true;
        }
        
        return false;
    }
    
    
    bool isPalinArray(vector<int> &arr) {
 
        for(auto ele : arr){
            if(!isPalindrome(ele)){
                return false;
            }
        }
        return true;
    }
};
