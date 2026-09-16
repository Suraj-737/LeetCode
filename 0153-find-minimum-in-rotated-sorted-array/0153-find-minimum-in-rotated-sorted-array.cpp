class Solution {
public:
int minn=INT_MAX;
    int findMin(vector<int>& nums) {
       
        bsearch(nums,0,nums.size()-1);
        return minn;
    }
    void bsearch(vector<int> & nums,int left, int right){
        if(left>right)return;
        minn=min(nums[left],minn);
        minn=min(nums[right],minn);
        int mid=(left+right)/2;
        minn=min(nums[mid],minn);
         if(nums[left]<=nums[mid]){
            if(nums[mid]>minn && nums[left]<=minn)return bsearch(nums,left,mid-1);
            else return bsearch(nums,mid+1,right);
            }
        
          else {
            if(nums[mid]<minn && nums[right]>minn) return bsearch(nums,mid+1,right);
            else return bsearch(nums,left,mid-1);
            
          }

    }
};