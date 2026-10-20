class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int lm=nums[0],m=nums[0],i=0;
        for(int j=1;j<nums.size();j++){
            m=max(m,nums[j]);
            if(nums[j]<lm) {i=j;
            lm=m; }
        }
        return i+1;
    
    }
};