class Solution {
public:
    int m;
    int k;
    string s;

    int solve(int i, int j, int idx) {
        if (idx == k) {
            return 0;
        }

        int ni = i, nj = j;

        if (s[idx] == 'R') {
            nj = j + 1;
        } else if (s[idx] == 'L') {
            nj = j - 1;
        } else if (s[idx] == 'U') {
            ni = i - 1;
        } else {
            ni = i + 1;
        }

        
        if (ni < 0 || ni >= m || nj < 0 || nj >= m) {
            return 0;
        }

        return 1 + solve(ni, nj, idx + 1);
    }

    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        this->s = s;
        m = n;
        k = s.size();
        vector<int> ans;

        for (int i = 0; i < s.size(); i++) {
            ans.push_back(solve(startPos[0], startPos[1], i));
        }

        return ans;
    }
};