class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;

        for (int i = 0; i < nums.size(); i++) {
            long long curr = nums[i];

            if (!st.empty() && curr == st.top()) {
                st.pop();
                curr *= 2;

                while (!st.empty() && curr == st.top()) {
                    st.pop();
                    curr *= 2;
                }

                st.push(curr);
            } else {
                st.push(curr);
            }
        }

        vector<long long> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};