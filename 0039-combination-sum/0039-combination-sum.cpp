class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> result;
        solve(candidates,target,temp,result,0);
        return result;
    }
    void solve(vector<int> & candidates,int target,vector<int> & temp,vector<vector<int>>& result, int idx){
        if(target==0){result.push_back(temp); return;}
        if(target<0 || idx>=candidates.size()) return;
        temp.push_back(candidates[idx]);
        solve(candidates,target-candidates[idx],temp,result,idx);
        temp.pop_back();
        solve(candidates,target,temp,result,idx+1);
    }
};