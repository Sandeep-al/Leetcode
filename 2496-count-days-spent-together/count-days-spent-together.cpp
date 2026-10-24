class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> days_per_month = {31, 28, 31, 30, 31, 30,
                                      31, 31, 30, 31, 30, 31};

        vector<int> prefix(13, 0);
        prefix[1] = days_per_month[0];
        for (int i = 2; i <= 12; i++) {
            prefix[i] = days_per_month[i - 1] + prefix[i - 1];
        }
        int alice_arrive_day = stoi(arriveAlice.substr(3, 2));
        int alice_arrive_month = stoi(arriveAlice.substr(0, 2));
        int alice_leave_day = stoi(leaveAlice.substr(3, 2));
        int alice_leave_month = stoi(leaveAlice.substr(0, 2));

        int bob_arrive_day = stoi(arriveBob.substr(3, 2));
        int bob_arrive_month = stoi(arriveBob.substr(0, 2));
        int bob_leave_day = stoi(leaveBob.substr(3, 2));
        int bob_leave_month = stoi(leaveBob.substr(0, 2));

        int alice_start = alice_arrive_day + prefix[alice_arrive_month - 1];
        int alice_end = alice_leave_day + prefix[alice_leave_month - 1];
        int bob_start = bob_arrive_day + prefix[bob_arrive_month - 1];
        int bob_end = bob_leave_day + prefix[bob_leave_month - 1];

        int start = max(alice_start, bob_start);
        int end = min(alice_end, bob_end);

        return max(0, end - start + 1);

        
    }
};