class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        deque<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        dist[0][0] = 0;
        q.push_front({0, 0});

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();

            for(int d = 0; d < 4; d++) {
                int x = i + dx[d];
                int y = j + dy[d];

                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;

                int cost = (grid[i][j] == d + 1) ? 0 : 1;

                if(dist[i][j] + cost < dist[x][y]) {
                    dist[x][y] = dist[i][j] + cost;

                    if(cost == 0)
                        q.push_front({x, y});
                    else
                        q.push_back({x, y});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};