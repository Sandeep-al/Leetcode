class Solution {
public:
    vector<string> ans;
    string curr = "";
    int n;
    string s;

    void solve(int idx, int parts) {

        if (idx == n) {
            if (parts == 4) {

                ans.push_back(curr);
                ans.back().pop_back();
            }
            return;
        }
        if (parts == 4) {
            return;
        }
        // leading zeroes case;
        if (s[idx] == '0') {
            curr += "0.";
            solve(idx + 1, parts + 1);
            curr.pop_back();
            curr.pop_back();
        } else {

            for (int i = idx; i < min(n, idx + 3); i++) {

                string temp = s.substr(idx, i - idx + 1);

                if (stoi(temp) <= 255) {
                    curr += temp;
                    curr.push_back('.');

                    solve(i + 1, parts + 1);

                    int len = i - idx + 2;
                    while (len > 0) {
                        curr.pop_back();
                        len--;
                    }
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        this->s = s;
        solve(0, 0);
        return ans;
    }
};