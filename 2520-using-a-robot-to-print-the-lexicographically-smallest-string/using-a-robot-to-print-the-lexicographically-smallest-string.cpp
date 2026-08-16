class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();

        vector<char> suffixMin(n+1);
        suffixMin[n]='{';

        for (int i = n - 1; i >= 0; i--) {
            suffixMin[i] = min(s[i], suffixMin[i + 1]);
        }

        stack<char> st;
        string ans;

        for (int i = 0; i < n; i++) {
            st.push(s[i]);

            while (!st.empty() && st.top() <= suffixMin[i+1]) {
                ans += st.top();
                st.pop();
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};