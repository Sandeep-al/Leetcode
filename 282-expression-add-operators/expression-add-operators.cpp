class Solution {
public:
    vector<string> final_ans;
    string s;
    int target;

    void compute(int i, long current_sum, long prev_val, string path) {

        if (i == s.size()) {
            if (current_sum == target) {
                final_ans.push_back(path);
            }
            return;
        }

        for (int j = i; j < s.size(); j++) {

            if (j > i && s[i] == '0')
                break;

            string numStr = s.substr(i, j - i + 1);
            long curr = stol(numStr);

            if (i == 0) {
                compute(j + 1, curr, curr, numStr);
            } else {

                compute(j + 1, current_sum + curr, curr, path + "+" + numStr);

                compute(j + 1, current_sum - curr, -curr, path + "-" + numStr);

                compute(j + 1, (current_sum - prev_val) + (prev_val * curr),
                        prev_val * curr, path + "*" + numStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        this->s = num;
        this->target = target;
        compute(0, 0, 0, "");
        return final_ans;
    }
};