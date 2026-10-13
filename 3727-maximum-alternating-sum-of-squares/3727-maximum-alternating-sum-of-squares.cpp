class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)
                nums[i]=nums[i]*(-1);  
        }
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
         long long score=0;
        while(l<r){
            score+=(nums[r]*nums[r])-(nums[l]*nums[l]);
            cout<<score;
            r--;
            l++;
        }
        if(nums.size()%2!=0){
            score+=nums[r]*nums[r];
        }

return score;

        
    }
};