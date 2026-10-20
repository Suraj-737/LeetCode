class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans=nums;
        sort(ans.begin(),ans.end());
       unordered_map<int,int> mp;
       for(int i=0;i<ans.size();i++){
        if(mp.find(ans[i]) == mp.end()) {
                mp[ans[i]] = i;
            }
       }
       for(int i=0;i<nums.size();i++){
        ans[i]=mp[nums[i]];
       }
       return ans;
    }
};