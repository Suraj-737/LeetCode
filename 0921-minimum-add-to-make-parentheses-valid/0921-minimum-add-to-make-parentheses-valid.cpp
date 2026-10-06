class Solution {
public:
    int minAddToMakeValid(string s) {
        int opn = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                opn++;

            else
                opn--;

            if (opn < 0) {
                opn++;
                res++;
            }
        }
        return opn + res;
    }
};