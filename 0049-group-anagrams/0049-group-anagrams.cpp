class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> results;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
         
                mp[temp].push_back(strs[i]);
            }
            for(auto&p:mp){
                results.push_back(p.second);
            }
    return results;
    }

    
};