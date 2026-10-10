class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(nums1.size());
        int maxi = 0;

        for(int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
        }

        long long k = (long long)k1 + k2;
        vector<long long> cnt(maxi + 1, 0);

        for(int x : diff)
            cnt[x]++;

        for(int i = maxi; i > 0 && k > 0; i--) {
            long long take = min(k, cnt[i]);
            cnt[i] -= take;
            cnt[i - 1] += take;
            k -= take;
        }

        long long ans = 0;

        for(int i = 1; i <= maxi; i++)
            ans += cnt[i] * i * i;

        return ans;
    }
};