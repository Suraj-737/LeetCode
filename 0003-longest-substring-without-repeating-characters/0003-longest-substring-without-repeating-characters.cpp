class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,maxlen=0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(mp[s[i]]>1){
                mp[s[l]]--;
                l++;

            }
            
            maxlen=max(maxlen,i-l+1);
        }
        return maxlen;
    }
};