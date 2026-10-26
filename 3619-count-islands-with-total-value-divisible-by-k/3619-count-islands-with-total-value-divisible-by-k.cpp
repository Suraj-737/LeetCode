class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                  if(dfs(grid,i,j)%k==0) ans++;
                }
            }
        }
        return ans;
    }
    long long dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[i].size()) return 0;
        if(grid[i][j]==0) return 0;
        long long x=grid[i][j];
        grid[i][j]=0;
        long long a=dfs(grid,i+1,j);
        long long b=dfs(grid,i-1,j);
        long long d=dfs(grid,i,j+1);
        long long c=dfs(grid,i,j-1);
        return a+b+c+d+x;
 
    }
};