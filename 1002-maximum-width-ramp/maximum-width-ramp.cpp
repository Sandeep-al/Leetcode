class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (!st.empty() && nums[i] >= nums[st.top()]) {
                continue;
            }

            st.push(i);
        }
        int maxi = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                maxi = max(maxi, i - st.top());
                st.pop();
            }
        }
        return maxi;
    }
};