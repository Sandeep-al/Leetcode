class Solution {
public:
    int m;
    unordered_set<string> st;
    vector<int>dp;
    bool solve(string& s, int i) {
        if (i == m) {
            return true;
        }
        if(dp[i]!=-1) return dp[i];
        string curr = "";

        for (int x = i; x <= m - 1; x++) {

            curr += s[x];

            if (st.find(curr) != st.end()) {
                if (solve(s, x + 1)) {
                    return dp[i]=true;
                }
            }
        }

        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        m=s.size();
        for (auto& it : wordDict) {
            st.insert(it);
        }
        dp.assign(m+1,-1);
        return solve(s, 0);
    }
};