class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result;
        int cnt = 0;
        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                result.push_back(cnt%2);
                cnt++;
            }
            if (seq[i] == ')') {
                cnt--;
                result.push_back(cnt%2);
            }
        }
        return result;
    }
};