class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0, req = 0;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                cnt++;
                i++;
            } else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    if (cnt > 0)
                        cnt--;
                    else
                        req++;
                    i += 2;
                } else {
                    if (cnt > 0) {
                        req++;
                        cnt--;
                    } else
                        req+=2;
                    i++;
                }
            }
        }
        return req + cnt * 2;
    }
};