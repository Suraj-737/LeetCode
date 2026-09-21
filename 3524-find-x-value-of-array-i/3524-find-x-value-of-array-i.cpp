class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
         vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for(int x : nums) {
            int val = x % k;
            vector<long long> next(k, 0);

            // Start a new subarray
            next[val]++;

            // Extend previous subarrays
            for(int r = 0; r < k; r++) {
                int newr = (r * val) % k;
                next[newr] += dp[r];
            }

            // Add all subarrays ending here
            for(int r = 0; r < k; r++)
                ans[r] += next[r];

            dp = next;
        }

        return ans;
        
    }
};