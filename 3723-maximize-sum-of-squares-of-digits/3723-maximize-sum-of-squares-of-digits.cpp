class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
         if(sum > 9 * num) return "";

        string ans = "";

        while(num > 0) {
            int x = min(9, sum);
            ans += to_string(x);
            sum -= x;
            num--;
        }

        return ans;
        }
    
};