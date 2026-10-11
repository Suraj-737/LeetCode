class Solution {
public:
    string removeDuplicateLetters(string s) {
        
           vector<int> freq(26,0);
        vector<bool>seen(26,false);
        string ans="";
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']--;
            if(seen[s[i]-'a']) continue;

            while(!ans.empty()&& ans.back()>s[i]&& freq[ans.back()-'a']>0){
                seen[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            seen[s[i]-'a']=true;
        }
        return ans;
        
    }
};