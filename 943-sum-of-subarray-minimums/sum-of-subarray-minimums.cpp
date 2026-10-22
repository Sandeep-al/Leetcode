class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> right(n, n);
        vector<int> left(n, -1);

        stack<int> st;
      
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) { 
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        st = {};

        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int total = 0;

        for (int i = 0; i < n; i++) {
            
            long long l = i - left[i];
            long long r = right[i] - i;

            long long contribution = (l * r) % MOD;
            contribution = (contribution * arr[i]) % MOD;

            total = (total + contribution) % MOD;
        }

        return total;
    }
};
