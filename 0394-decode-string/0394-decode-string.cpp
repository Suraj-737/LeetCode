class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> st;
        string temp = "";
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]))
                cnt = cnt * 10 + (s[i] - '0');
            else if (s[i] == '[') {
                nums.push(cnt);
                st.push(temp);
                cnt = 0;
                temp = "";
            } else if (s[i] == ']') {
                int x = nums.top();
                nums.pop();

                string prev = st.top();
                st.pop();
                string t = "";
                for (int j = 0; j < x; j++) {
                    t += temp;
                }
                temp = prev + t;

            } else
                temp += s[i];
        }
        return temp;
    }
};