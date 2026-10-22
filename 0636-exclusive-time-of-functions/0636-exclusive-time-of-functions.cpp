class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> ans(n, 0);
        int prev = 0;

        for(int i = 0; i < logs.size(); i++) {
            stringstream ss(logs[i]);
            string id, type, time;

            getline(ss, id, ':');
            getline(ss, type, ':');
            getline(ss, time, ':');

            int x = stoi(id);
            int t = stoi(time);

            if(type == "start") {
                if(!st.empty())
                    ans[st.top()] += t - prev;

                st.push(x);
                prev = t;
            }
            else {
                ans[st.top()] += t - prev + 1;
                st.pop();
                prev = t + 1;
            }
        }

        return ans;
    }
};