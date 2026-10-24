class Solution {
public:
int dateToDay(string date) {
        int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int totalDays = day;
        for (int i = 1; i < month; ++i) {
            totalDays += daysInMonths[i];
        }
        return totalDays;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aArrival = dateToDay(arriveAlice);
        int aLeave = dateToDay(leaveAlice);
        int bArrival = dateToDay(arriveBob);
        int bLeave = dateToDay(leaveBob);
        
        int startOverlap = max(aArrival, bArrival);
        int endOverlap = min(aLeave, bLeave);
        
        return max(0, endOverlap - startOverlap + 1);

    }
};