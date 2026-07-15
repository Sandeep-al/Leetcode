class Solution {
public:
    string target; 
    string s;      
    int limit;     
    long long dp[20][2][2]; 

    long long solve(int idx, int tight, int started) {
        int N = target.size();
        int K = s.size();

        
        if (idx == N) {
            return started ? 1 : 0;
        }

        if (dp[idx][tight][started] != -1) {
            return dp[idx][tight][started];
        }

        long long ans = 0;
        int max_digit = tight ? (target[idx] - '0') : 9;

       
        int suffix_start_idx = N - K;

        if (idx >= suffix_start_idx) {
           
            int required_digit = s[idx - suffix_start_idx] - '0';

            
            if (required_digit <= limit && required_digit <= max_digit) {
                int next_tight = tight && (required_digit == max_digit);
                int next_started = started || (required_digit > 0);
                
                ans += solve(idx + 1, next_tight, next_started);
            }
        } 
        else {
            
            for (int digit = 0; digit <= min(max_digit, limit); digit++) {
                int next_tight = tight && (digit == max_digit);
                int next_started = started || (digit > 0);

                ans += solve(idx + 1, next_tight, next_started);
            }
        }

        return dp[idx][tight][started] = ans;
    }

    long long countPowerful(string val) {
        
        if (val.size() < s.size()) return 0;

        target = val;
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0);
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        this->s = s;
        this->limit = limit;

        
        long long ans_finish = countPowerful(to_string(finish));
        long long ans_start = countPowerful(to_string(start - 1));

        return ans_finish - ans_start;
    }
};