class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> results;
        solve(s,temp,results,0);
        return results;
    }
    void solve(string s,vector<string>& temp,vector<vector<string>>& results,int i){
        if(i==s.size()){
            results.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            string str=s.substr(i,j-i+1);
            string rev=str;
            reverse(rev.begin(),rev.end());
            if(str==rev){
                temp.push_back(str);
                solve(s,temp,results,j+1);
                temp.pop_back();
            }
        }
    }
};