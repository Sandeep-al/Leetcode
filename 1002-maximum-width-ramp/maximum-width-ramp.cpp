class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int maxi = 0;
        st.push(0);
        int n=nums.size();
        for (int i = 1; i < nums.size(); i++) {

            if (!st.empty() && nums[st.top()] > nums[i]) {

                st.push(i);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                maxi = max(maxi, i - st.top());
                st.pop();
            }
        }

        return maxi;
    }
};
