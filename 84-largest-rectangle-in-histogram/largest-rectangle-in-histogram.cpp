class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n, n);   
        vector<int> left(n, -1);

        stack<int> st;

        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) { 
                st.pop();
            }

            if (!st.empty())
                right[i] = st.top();

            st.push(i);
        }

        st = {};

        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {  
                st.pop();
            }

            if (!st.empty())
                left[i] = st.top();

            st.push(i);
        }

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;  
            maxi = max(maxi, width * heights[i]);
        }

        return maxi;
    }
};