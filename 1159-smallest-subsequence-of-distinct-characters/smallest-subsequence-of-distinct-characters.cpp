class Solution {
public:
    string smallestSubsequence(string s) {
        int last_idx[26];

        for (int i = 0; i < s.size(); i++) {
            last_idx[s[i] - 'a'] = i;
        }

        stack<char> st;
        unordered_set<char> seen;

        for (int i = 0; i < s.size(); i++) {

            if (seen.find(s[i]) != seen.end()) {
                continue;
            }

            while (!st.empty() && s[i] < st.top() &&
                   last_idx[st.top() - 'a'] > i) {

                seen.erase(st.top());
                st.pop();
            }

            st.push(s[i]);
            seen.insert(s[i]);
        }

        string s1 = "";
        while (!st.empty()) {
            s1.push_back(st.top());
            st.pop();
        }

        reverse(s1.begin(), s1.end());
        return s1;
    }
};