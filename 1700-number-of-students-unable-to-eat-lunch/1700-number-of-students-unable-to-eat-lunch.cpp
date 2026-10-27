class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> q;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int i=0, cnt=0;
        while(i<sandwiches.size()){
            if(q.front()==sandwiches[i]){
                q.pop();
                i++;
                cnt=0;
            }
            else{
                int j=q.front();
                q.pop();
                q.push(j);
                cnt++;
                if(cnt==q.size()) break;
            }
        }
        return q.size();
    }
};