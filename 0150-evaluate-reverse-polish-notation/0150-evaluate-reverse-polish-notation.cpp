class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int temp = 0;
                if (tokens[i] == "+")
                    temp = b + a;
                else if (tokens[i] == "-")
                    temp = b - a;
                else if (tokens[i] == "*")
                    temp = b * a;
                else if (tokens[i] == "/")
                    temp = b / a;
                st.push(temp);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};