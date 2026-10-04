class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        int temp=n&n-1;
        if(temp==0) return true;
        else return false;
        
    }
};