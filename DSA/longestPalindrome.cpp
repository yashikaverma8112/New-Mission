//https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

class Solution {
  public:
  
    bool isPalindrome(string &s, int start, int end){
        while(start < end){
            if(s[start]!= s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    string longestPalindrome(string &s) {
        int n = s.size();
        
        string ans = "";
        int maxLen = 0;
        int start = 0;
        
        int i = 0;
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(s,i,j) && (j-i+1 > maxLen)){
                    maxLen = j-i+1;
                    start = i;
                }
            }
        }
        return s.substr(start,maxLen);
    }
};
