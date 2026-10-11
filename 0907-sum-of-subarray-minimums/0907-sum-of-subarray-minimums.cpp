class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>st;
        long long ans=0;
        for(int i=0;i<=arr.size();i++){
            while(!st.empty()&&(i==arr.size()||arr[st.top()]>arr[i])){
                int idx=st.top();
                st.pop();
                int l=st.empty()?idx+1:idx-st.top();
                int r=i-idx;
                ans=(ans+(long long)arr[idx]*l*r)%1000000007;
            }
            st.push(i);
        }
        return ans;
        
    }
};