#include<iostream>
#include<vector>
using namespace std;

vector<int>computeLPS(string &s2){
    int n = s2.size();
    vector<int>lps(n,0);
    int len = 0;
    int i = 1;
    
    while(i<n){
        if(s2[i]==s2[len]){
            len++;
            lps[len];
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


bool areRotations(string &s1, string &s2){
    if(s1.length() != s2.length()){
        return false;
    }
    string txt = s1+s1;
    string pat = s2;

    int i = 0, j = 0;
    vector<int>lps = computeLPS(s2);
    while(i<txt.length()){
        if(txt[i]!=pat[j]){
            i++;
            j++;
        }
        if(j==pat.length()){
            return false;
        }
        else if(i<txt.length() && txt[i] != pat[j]){
            if(j!=0){
                j = lps[j-1];
                
            }
            else{
                i++;
            }
        }
    }
}

int main() {
    string s1 = "aab"; 
  	string s2 = "aba";
  	
    cout << (areRotations(s1, s2) ? "true" : "false");
    return 0;
}