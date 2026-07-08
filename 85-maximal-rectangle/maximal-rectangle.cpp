class Solution {
public:
    int solve(vector<int>& heights) {
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
    int maximalRectangle(vector<vector<char>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> heights(rows);
        vector<int> prev(cols, 0);
        for (int i = 0; i < rows; i++) {
            vector<int> curr(cols, 0);
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '0') {
                    curr[j] = 0;
                } else {
                    curr[j] = prev[j] + 1;
                }
            }
            prev=curr;
            heights[i] = curr;
        }

        int maxi=0;
        for(int i=0;i<rows;i++){
            int curr= solve(heights[i]);
            maxi=max(maxi,curr);
        }

        return maxi;
    }
};