class Solution {
public:
    unordered_map<int, string> mpp = {{2, "abc"}, {3, "def"}, {4, "ghi"},
                                      {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
                                      {8, "tuv"}, {9, "wxyz"}};

    vector<string> final_ans;
    string curr = "";
    string digits;
    int n;
    void solve(int idx) {
        if (idx == n) {
            final_ans.push_back(curr);
            return;
        }

        int c = digits[idx] - '0';
        for (auto& it : mpp[c]) {
            curr.push_back(it);
            solve(idx + 1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        this->digits = digits;
        solve(0);
        return final_ans;
    }
};