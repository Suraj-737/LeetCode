class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int secsml=INT_MAX,sml=INT_MAX,seclrg=INT_MIN,lrg=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>lrg){
                seclrg=lrg;
                lrg=nums[i];
            }
            else if(seclrg<nums[i]){
                seclrg=nums[i];
            }
            if(nums[i]<sml){
                secsml=sml;
                sml=nums[i];
            }
            else if(secsml>nums[i]){
                secsml=nums[i];
            }
        }
        int ans=(lrg*seclrg)-(sml*secsml);
        return ans;
    }
};