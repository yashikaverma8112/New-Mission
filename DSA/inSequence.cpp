// https://www.geeksforgeeks.org/problems/arithmetic-number2815/1

class Solution {
  public:
    int inSequence(int a, int b, int c) {
        // code here
        /*
        int i = a;
        
        while(i!=b){
            i += c;
            
            if(i==b){
                return true;
            }
        }
        return false;
        */
        
        return (b-a) % c == 0;
    }
};
