class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int number = 0;
        unordered_set<int> st;
        int po = 1;
        for (int i = 0; i < k - 1; i++) {
            po = po * 2;
        }
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                if (s[i - k] == '1') {
                    number -= po;
                }
            }
            if (s[i] == '1') {
                number = number * 2 + 1;
            } else {
                number = number * 2;
            }

            if (i >= k - 1) {
                st.insert(number);
            }
        }

        return st.size() == (po * 2);
    }
};