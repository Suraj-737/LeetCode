class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxcnt = 0;

        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            maxcnt = max(maxcnt, cnt);
            if (s[i] == '(') {
                cnt++;
            } else if (s[i] == ')') {
                cnt--;
            }

            else
                continue;
        }
        return maxcnt;
    }
};