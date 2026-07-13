class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        if (numRows == 1)
            return s;
        int row = 0;
        int down = 1;
        int idx = 0;
        int n = s.size();

        while (idx < n) {
            rows[row].push_back(s[idx]);
            idx++;

            if (row == 0)
                down = true;

            if (row == numRows - 1)
                down = false;

            if (down)
                row++;
            else
                row--;
        }

        string ans = "";
        for (int i = 0; i < numRows; i++) {
            ans += rows[i];
        }

        return ans;
    }
};