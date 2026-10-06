class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>>results;
        solve(nums,temp,results,0);
        return results;
    }
    void solve(vector<int>& nums,vector<int>& temp,vector<vector<int>>&results,int idx){
        if(idx>nums.size()-1){
            results.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums,temp,results,idx+1);
        temp.pop_back();
        solve(nums,temp,results,idx+1);
    }
};