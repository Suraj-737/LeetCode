class Solution {
public:
    const long long mod = 1000000007;
    vector<long long> sum, sq, lazy;

    void push(int node, int l, int r) {
        if(lazy[node] == 0) return;

        long long x = lazy[node];
        long long len = r - l + 1;

        sq[node] = (sq[node] + 2 * x * sum[node] + len * x * x) % mod;
        sum[node] = (sum[node] + len * x) % mod;

        if(l != r) {
            lazy[node * 2] += x;
            lazy[node * 2 + 1] += x;
        }

        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        push(node, l, r);

        if(l > qr || r < ql) return;

        if(l >= ql && r <= qr) {
            lazy[node]++;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % mod;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % mod;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            int l = last[nums[i]] + 1;

            update(1, 0, n - 1, l, i);

            ans = (ans + sq[1]) % mod;
            last[nums[i]] = i;
        }

        return ans;
    }
};