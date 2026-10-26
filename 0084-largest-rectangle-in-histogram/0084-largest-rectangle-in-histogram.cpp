class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int>st;
        for(int i=0;i<=heights.size();i++){
            int h=(i==heights.size())?0:heights[i];

            while(!st.empty()&& h<heights[st.top()]){
                int height=heights[st.top()];
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                ans=max(ans,width*height);
            }
            st.push(i);
        }
        return ans;
    }
};