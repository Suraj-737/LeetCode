class Solution {
public:
    void merge(vector<pair<pair<int,int>,int>>& v, int l, int mid, int r) {
        vector<pair<pair<int,int>,int>> temp;

        int i = l, j = mid + 1;

        while(i <= mid && j <= r) {
            if(v[i].first <= v[j].first) {
                temp.push_back(v[i]);
                i++;
            }
            else {
                temp.push_back(v[j]);
                j++;
            }
        }

        while(i <= mid) {
            temp.push_back(v[i]);
            i++;
        }

        while(j <= r) {
            temp.push_back(v[j]);
            j++;
        }

        for(int k = l; k <= r; k++) {
            v[k] = temp[k - l];
        }
    }

    void mergeSort(vector<pair<pair<int,int>,int>>& v, int l, int r) {
        if(l >= r) return;

        int mid = l + (r - l) / 2;

        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, r);

        merge(v, l, mid, r);
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int,int>,int>> v;

        for(int i = 0; i < n; i++) {
            int x = nums[i];
            int s = 0;

            while(x > 0) {
                s += x % 10;
                x /= 10;
            }

            v.push_back({{s, nums[i]}, i});
        }

        mergeSort(v, 0, n - 1);

        vector<int> pos(n);

        for(int i = 0; i < n; i++) {
            pos[v[i].second] = i;
        }

        vector<bool> seen(n, false);
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(seen[i] || pos[i] == i) continue;

            int cnt = 0;
            int j = i;

            while(!seen[j]) {
                seen[j] = true;
                j = pos[j];
                cnt++;
            }

            ans += cnt - 1;
        }

        return ans;
    }
};