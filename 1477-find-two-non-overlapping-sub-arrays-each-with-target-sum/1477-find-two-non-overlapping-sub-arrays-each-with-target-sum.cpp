class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = INT_MAX;

        unordered_map<int,int> mp;
        vector<int> dp(n, INT_MAX);

        mp[0] = -1;

        int sum = 0;
        int best = INT_MAX;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(mp.count(sum - target)) {
                int j = mp[sum - target];
                int len = i - j;

                if(j >= 0 && dp[j] != INT_MAX)
                    ans = min(ans, len + dp[j]);

                best = min(best, len);
            }

            dp[i] = best;
            mp[sum] = i;
        }
        return ans==INT_MAX?-1:ans;

    }
};