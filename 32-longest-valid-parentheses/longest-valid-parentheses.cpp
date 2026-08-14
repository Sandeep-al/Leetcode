class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxi = 0;
        
        stack<int> st;
        int last = -1;

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else {
                if (!st.empty()) {
                    st.pop();

                    if (st.empty()) {
                        maxi = max(maxi, i - last);
                    }
                    else {
                        maxi = max(maxi, i - st.top());
                    }
                }
                else {
                    last = i;
                }
            }
        }

        return maxi;
    }
};