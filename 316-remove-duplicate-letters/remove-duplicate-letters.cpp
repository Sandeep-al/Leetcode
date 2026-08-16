class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> last(26, 0);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> vis(26, 0);

        for (int i = 0; i < s.size(); i++) {

            char curr = s[i];

            if (vis[curr - 'a'])
                continue;

            while (!st.empty() &&
                   st.top() > curr &&
                   last[st.top() - 'a'] > i) {

                vis[st.top() - 'a'] = 0;
                st.pop();
            }

            st.push(curr);
            vis[curr - 'a'] = 1;
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};