class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        solve(n,results,"",0);
        return  results;
    }
    void solve(int n,vector<string>& results,string d,int cnt){
        if(n==0 && cnt==0){
            results.push_back(d);
            return;
        }
        if(n>0){
            solve(n-1,results,d+'(',cnt+1);
        }
        if(cnt>0){
            solve(n,results,d+')',cnt-1);
        }
    }
};