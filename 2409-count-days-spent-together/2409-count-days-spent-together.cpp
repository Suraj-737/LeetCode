class Solution {
public:
    int daysBetween(string s) {
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

        int month = stoi(s.substr(0, 2));
        int day = stoi(s.substr(3, 2));

        for(int i = 0; i < month - 1; i++) {
            day += days[i];
        }

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a = daysBetween(arriveAlice);
        int b = daysBetween(leaveAlice);
        int c = daysBetween(arriveBob);
        int d = daysBetween(leaveBob);

        int start = max(a, c);
        int end = min(b, d);

        return max(0, end - start + 1);
    }
};