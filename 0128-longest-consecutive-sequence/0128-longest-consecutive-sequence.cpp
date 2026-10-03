class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 1)
            return 0;
        sort(nums.begin(), nums.end());
        int cnt = 1, maxcnt = 0;
        int curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                continue;
            if (nums[i] == curr + 1)
                cnt++;
            else {
                maxcnt = max(maxcnt, cnt);
                cnt = 1;
            }
            curr = nums[i];
        }
        return max(maxcnt,cnt);
    }
};