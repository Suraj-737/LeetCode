class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            long long p = 1;
            int g = 0, l = 1;

            for(int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                long long val = 1LL * g * l;

                if(p > val / nums[j])
                    break;

                p *= nums[j];

                if(p == val)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
        
    }
};