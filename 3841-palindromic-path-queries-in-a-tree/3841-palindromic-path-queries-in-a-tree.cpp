class Solution {
public:
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout, parent, pref;
    vector<int> bit;
    int timer = 0;

    void add(int i, int x, int n) {
        for(; i <= n + 1; i += i & -i)
            bit[i] ^= x;
    }

    int get(int i) {
        int ans = 0;
        for(; i > 0; i -= i & -i)
            ans ^= bit[i];
        return ans;
    }

    int mask(char c) {
        return 1 << (c - 'a');
    }

    int lca(int a, int b) {
        if(depth[a] < depth[b])
            swap(a, b);

        int diff = depth[a] - depth[b];

        for(int k = 0; k < LOG; k++) {
            if(diff & (1 << k))
                a = up[k][a];
        }

        if(a == b)
            return a;

        for(int k = LOG - 1; k >= 0; k--) {
            if(up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }

        return parent[a];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        adj.assign(n, {});
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while((1 << LOG) <= n)
            LOG++;

        parent.assign(n, 0);
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        pref.assign(n, 0);

        vector<int> order;
        vector<int> st = {0};
        parent[0] = 0;
        pref[0] = mask(s[0]);

        while(!st.empty()) {
            int u = st.back();
            st.pop_back();

            tin[u] = order.size();
            order.push_back(u);

            for(int v : adj[u]) {
                if(v == parent[u])
                    continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                pref[v] = pref[u] ^ mask(s[v]);
                st.push_back(v);
            }
        }

        vector<int> sz(n, 1);

        for(int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[parent[u]] += sz[u];
        }

        for(int i = 0; i < n; i++)
            tout[i] = tin[i] + sz[i] - 1;

        up.assign(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = parent[i];

        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++)
                up[k][i] = up[k-1][up[k-1][i]];
        }

        bit.assign(n + 2, 0);
        vector<bool> ans;

        for(string &q : queries) {
            string type;
            int u;
            string x;

            stringstream ss(q);
            ss >> type >> u >> x;

            if(type == "update") {
                char c = x[0];
                int delta = mask(s[u]) ^ mask(c);

                if(delta != 0) {
                    add(tin[u] + 1, delta, n);
                    add(tout[u] + 2, delta, n);
                }

                s[u] = c;
            }
            else {
                int v = stoi(x);
                int w = lca(u, v);

                int pu = pref[u] ^ get(tin[u] + 1);
                int pv = pref[v] ^ get(tin[v] + 1);

                int path = pu ^ pv ^ mask(s[w]);

                ans.push_back((path & (path - 1)) == 0);
            }
        }

        return ans;
    }
};