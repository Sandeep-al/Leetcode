class Solution {
public:
    vector<vector<string>> final_ans;
    vector<string> temp;
    int n;
    bool palindrome(string x) {
        int z = x.size();
        int i = 0;

        while (i < z / 2) {

            if (x[i] != x[z - 1 - i]) {
                return false;
            }
            i++;
        }
        return true;
    }
    void partition(int i,string &s) {
        if (i == n) {
            final_ans.push_back(temp);
        }

        for (int j = i; j < n; j++) {
            if (palindrome(s.substr(i, j - i + 1))) {
                temp.push_back(s.substr(i, j - i + 1));
                partition(j + 1,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        partition(0,s);
        return final_ans;
    }
};