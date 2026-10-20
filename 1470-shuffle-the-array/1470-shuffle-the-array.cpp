class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n,0);
        for(int i=0;i<2*n;i+=2){
            ans[i]=nums[i/2];
            ans[i+1]=nums[n+i/2];

        }
        return ans;
        
    }
};