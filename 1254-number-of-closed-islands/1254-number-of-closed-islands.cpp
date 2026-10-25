class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    
                   if( dfs(grid,i,j)) ans++;

                }
            }
        }
        return ans;
        
    }
    bool dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[i].size()) return false;
        if(grid[i][j]==1) return true;
        grid[i][j]=1;
        bool a=dfs(grid,i-1,j);
        bool b= dfs(grid,i+1,j);
         bool c=dfs(grid,i,j-1);
         bool d=dfs(grid,i,j+1);
         return a&&b&&c&&d;

    }
};