class Solution {
public:
    int findDayofYear(string date, vector<int>& cumMonthDays) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        return cumMonthDays[month - 1] + day;
    }

    int countDaysTogether(string arriveAlice,
                          string leaveAlice,
                          string arriveBob,
                          string leaveBob) {

        vector<int> monthDays =
            {31,28,31,30,31,30,31,31,30,31,30,31};

        vector<int> cumMonthDays(13, 0);

        for(int i = 1; i <= 12; i++) {
            cumMonthDays[i] =
                cumMonthDays[i - 1] + monthDays[i - 1];
        }

        int arriveAliceDay = findDayofYear(arriveAlice, cumMonthDays);
        int leaveAliceDay = findDayofYear(leaveAlice, cumMonthDays);

        int arriveBobDay = findDayofYear(arriveBob, cumMonthDays);
        int leaveBobDay = findDayofYear(leaveBob, cumMonthDays);

        int overlapDays =
            min(leaveAliceDay, leaveBobDay)
            - max(arriveAliceDay, arriveBobDay)
            + 1;

        return max(0, overlapDays);
    }
};
