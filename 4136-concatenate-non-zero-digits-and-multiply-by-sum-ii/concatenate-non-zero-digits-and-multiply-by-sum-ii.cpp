class Solution {
public:
    const int mod = 1e9 + 7;
    void compute_pow_10(vector<int>& pow10) {
        for (int i = 1; i < pow10.size(); i++) {
            pow10[i] = (1LL * pow10[i - 1] * 10) % mod;
        }
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefix_sum(n);
        vector<int> prefix_number(n);
        vector<int> prefix_non_zero(n);
        int curr_number = 0;
        int curr_sum = 0;
        int curr_non_zero = 0;
        vector<int> pow10(n + 1, 1);
        compute_pow_10(pow10);
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                int current_digit = s[i] - '0';
                curr_sum = (curr_sum + current_digit) % mod;
                curr_number = (1LL * curr_number * 10 + current_digit) % mod;
                curr_non_zero += 1;
            }
            prefix_sum[i] = curr_sum;
            prefix_number[i] = curr_number;
            prefix_non_zero[i] = curr_non_zero;
        }
        vector<int> answer;
        for(auto query : queries){
            int start_idx = query[0];
            int end_idx = query[1];
            int prev_non_zero = (start_idx > 0) ? prefix_non_zero[start_idx - 1] : 0;
            int actual_length = prefix_non_zero[end_idx] - prev_non_zero;
            int prev_sum = (start_idx > 0) ? prefix_sum[start_idx - 1] : 0;
            int sum = (prefix_sum[end_idx] - prev_sum + mod) % mod;
            int actual_number = 0;
            if (actual_length > 0) {
                int prev_num = (start_idx > 0) ? prefix_number[start_idx - 1] : 0;
                int subtractor = (1LL * prev_num * pow10[actual_length]) % mod;
                actual_number = (prefix_number[end_idx] - subtractor + mod) % mod;
            }
            int ans = (1LL * actual_number * sum) % mod;
            answer.push_back(ans);
        }
        return answer;
    }
};