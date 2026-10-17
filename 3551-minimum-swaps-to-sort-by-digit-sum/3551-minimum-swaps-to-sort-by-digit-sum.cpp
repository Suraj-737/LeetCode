class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int,int>,int>> v;

        for(int i = 0; i < n; i++) {
            int x = nums[i], s = 0;

            while(x > 0) {
                s += x % 10;
                x /= 10;
            }

            v.push_back({{s, nums[i]}, i});
        }

        sort(v.begin(), v.end());

        vector<int> pos(n);

        for(int i = 0; i < n; i++) {
            pos[v[i].second] = i;
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i] || pos[i] == i) continue;

            int cnt = 0, j = i;

            while(!vis[j]) {
                vis[j] = true;
                j = pos[j];
                cnt++;
            }

            ans += cnt - 1;
        }

        return ans;
    }
};