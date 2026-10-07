class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> results;
        vector<bool>u(nums.size(),false);
        solve(nums,temp,results,u);

        return results;
    }
    void solve(vector<int>& nums,vector<int>&temp,vector<vector<int>>&results,vector<bool>&u){
        if(temp.size()==nums.size()){
            results.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(u[i]==false) u[i]=true;
            else continue;
            temp.push_back(nums[i]);
            solve(nums,temp,results,u);
            temp.pop_back();
            u[i]=false;
        }

    }
};