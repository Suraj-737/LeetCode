class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;

        vector<vector<int>> results;
        solve(candidates,target,temp,results,0);
        return results;
    }
    void solve(vector<int>& candidates,int target,vector<int>& temp,vector<vector<int>>& results,int idx){
        if(target==0){results.push_back(temp);
        return;}
        if(target<0 || idx>=candidates.size()) return;
        for(int i = idx; i < candidates.size(); i++) {

            if(i > idx && candidates[i] == candidates[i-1])
                continue;

            if(candidates[i] > target)
                break;

        temp.push_back(candidates[i]);
        solve(candidates,target-candidates[i],temp,results,i+1);
        temp.pop_back();
    }
    }
};