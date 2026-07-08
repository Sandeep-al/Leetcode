class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        
        for (int i = 0; i < nums.size(); i++) {
            if (st.empty()) {
                st.push(i);
                continue;
            }

            int top = nums[st.top()];

            if (top > nums[i]) {
                st.push(i);
            }
        }

        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            int curr=nums[i];

            while(!st.empty() && curr>=nums[st.top()]){
                ans=max(ans,i-st.top());
                st.pop();
            }
        }

        return ans;
    }
};