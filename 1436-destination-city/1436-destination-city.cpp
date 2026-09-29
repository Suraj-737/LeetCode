class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;
        for(auto x: paths){
            st.insert(x[0]);
        }
        for(auto x:paths){
            if(st.find(x[1])==st.end())
            return x[1];
        }
        return "";        
    }
};