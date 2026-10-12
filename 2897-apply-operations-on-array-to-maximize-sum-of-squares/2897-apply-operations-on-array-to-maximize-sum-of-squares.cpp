class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> freq(31, 0);
        long long ans = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < 31; j++) {
                if(nums[i] & (1 << j)) {
                    freq[j]++;
                }
            }
        }

        for(int i = 0; i < k; i++) {
            long long x = 0;

            for(int j = 0; j < 31; j++) {
                if(freq[j] > 0) {
                    x |= (1LL << j);
                    freq[j]--;
                }
            }

            ans = (ans + x * x) % mod;
        }

        return ans;
    }
};