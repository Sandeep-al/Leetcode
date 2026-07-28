class Solution {
public:
    void push_times(string& x, int count, char s) {
        for (int i = 0; i < count; i++) {
            x.push_back(s);
        }
    }
    string smallestPalindrome(string s) {
        unordered_map<char, int> mpp;
        for (auto& it : s) {
            mpp[it]++;
        }
        string final_ans = "";
        char middle = '#';
        for (auto& it : mpp) {
            if (it.second % 2 == 1) {
                middle = it.first;
            }
            int count = it.second  / 2;
            push_times(final_ans, count, it.first);
        }

        string ans = ""; sort(final_ans.begin(), final_ans.end());
        ans += final_ans;
        if (middle != '#') {
            ans.push_back(middle);
        }
        reverse(final_ans.begin(), final_ans.end());
        ans += final_ans;

        return ans;

        // aa cc dd
        // a c d d c a
        // aa c bb dd
        // abd c dba

        //jj eee jj
    }
};