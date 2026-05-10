class Solution {
public:
    vector<string> final_ans;

    vector<int> hours = {1, 2, 4, 8};
    vector<int> mins = {1, 2, 4, 8, 16, 32};

    void solve(int idx, int count, int h, int m) {

        if (h >= 12 || m >= 60)
            return;

        if (count == 0) {

            string time = to_string(h) + ":";

            if (m < 10)
                time += "0";

            time += to_string(m);

            final_ans.push_back(time);

            return;
        }

        if (idx == 10)
            return;

        if (idx < 4)
            solve(idx + 1, count - 1, h + hours[idx], m);
        else
            solve(idx + 1, count - 1, h, m + mins[idx - 4]);

        solve(idx + 1, count, h, m);
    }

    vector<string> readBinaryWatch(int turnedOn) {

        solve(0, turnedOn, 0, 0);

        return final_ans;
    }
};