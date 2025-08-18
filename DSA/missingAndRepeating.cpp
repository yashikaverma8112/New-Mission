class Solution {
public:
    vector<int> findTwoElement(vector<int> arr) {
        long long n = arr.size();
        
        // Calculate expected sum and sum of squares for 1 to n
        long long expectedSum = (n * (n + 1)) / 2;
        long long expectedSumSq = (n * (n + 1) * (2 * n + 1)) / 6;
        
        // Calculate actual sum and sum of squares from array
        long long actualSum = 0, actualSumSq = 0;
        for (int i = 0; i < n; i++) {
            actualSum += arr[i];
            actualSumSq += (long long)arr[i] * arr[i];
        }
        
        // Let missing = m, repeating = r
        // We have: expectedSum - actualSum = m - r  ... (1)
        // We have: expectedSumSq - actualSumSq = m² - r² = (m-r)(m+r)  ... (2)
        
        long long diff = expectedSum - actualSum;        // m - r
        long long sumDiff = (expectedSumSq - actualSumSq) / diff;  // m + r
        
        long long missing = (diff + sumDiff) / 2;    // (m-r + m+r) / 2 = m
        long long repeating = missing - diff;        // m - (m-r) = r
        
        return {(int)repeating, (int)missing};
    }
};
