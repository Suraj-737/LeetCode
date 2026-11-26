class Solution {
public:
    bool canAliceWin(int n) {
        int cnt=0;
        for(int i=10;i<=n;i--){
            n-=i;
            cnt++;
        }
        if(cnt%2==0) return false;
        else return true;
        
    }
};