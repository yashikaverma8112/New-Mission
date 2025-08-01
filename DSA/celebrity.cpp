class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
    
    int n = mat.size();
    stack<int> s;

    // Step 1: Push all people to the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Eliminate non-celebrities
    while (s.size() > 1) {
        int i = s.top(); s.pop();
        int j = s.top(); s.pop();

        // If i knows j => i can't be celebrity
        if (mat[i][j] == 1) {
            s.push(j);
        } 
        // Else j can't be celebrity
        else {
            s.push(i);
        }
    }

    // Step 3: Potential candidate
    int celeb = s.top();

    // Step 4: Verify the candidate
    for (int i = 0; i < n; i++) {
        if (i != celeb) {
            // celeb should not know anyone && everyone should know celeb
            if (mat[i][celeb] == 0 || mat[celeb][i] == 1) {
                return -1; // Not a celebrity
            }
        }
    }

    return celeb; // Valid celebrity found
}
};
