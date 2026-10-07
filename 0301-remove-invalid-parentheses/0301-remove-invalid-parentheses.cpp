class Solution {
public:
    vector<string> ans;

    vector<string> removeInvalidParentheses(string s) {
        ans.clear();
        int l = 0, r = 0;

        for (char c : s) {
            if (c == '(') l++;
            else if (c == ')') {
                if (l > 0) l--;
                else r++;
            }
        }

        string t;
        solve(s, 0, l, r, 0, t, false);
        return ans;
    }

    void solve(const string& s, int i, int l, int r,
               int cnt, string& t, bool kept) {

        if (i == (int)s.size()) {
            if (l == 0 && r == 0 && cnt == 0)
                ans.push_back(t);
            return;
        }

        char c = s[i];

        if (c != '(' && c != ')') {
            t.push_back(c);
            solve(s, i + 1, l, r, cnt, t, false);
            t.pop_back();
            return;
        }

        bool can = !(i > 0 && s[i-1] == c && kept);

        if (c == '(' && l > 0 && can)
            solve(s, i + 1, l - 1, r, cnt, t, false);
        if (c == ')' && r > 0 && can)
            solve(s, i + 1, l, r - 1, cnt, t, false);

        if (c == '(') {
            t.push_back(c);
            solve(s, i + 1, l, r, cnt + 1, t, true);
            t.pop_back();
        } else if (cnt > 0) {
            t.push_back(c);
            solve(s, i + 1, l, r, cnt - 1, t, true);
            t.pop_back();
        }
    }
};