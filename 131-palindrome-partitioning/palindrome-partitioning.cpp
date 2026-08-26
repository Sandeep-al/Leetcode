class Solution {
public:
    vector<vector<string>> final_ans;
    bool ispalindrome(string& x) {
        int l = 0;
        int h = x.size() - 1;
        while (l < h) {
            if (x[l] != x[h]) {
                return false;
            }
            l++;
            h--;
        }

        return true;
    }
    int n;
    string s;
    void solve(int idx, vector<string>& currs) {

        if (idx == n) {
            final_ans.push_back(currs);
        }
        string curr = "";
        for (int i = idx; i < n; i++) {
            curr += s[i];
            if (ispalindrome(curr)) {
                currs.push_back(curr);
                solve(i + 1, currs);
                currs.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        this->s = s;
        vector<string>x;
        solve(0,x);
        return final_ans;
    }
};