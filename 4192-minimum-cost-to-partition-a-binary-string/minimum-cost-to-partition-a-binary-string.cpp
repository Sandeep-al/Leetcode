class Solution {
public:
    vector<long long> prefix_sum;
    int flat;
    int enc;
    string s;
    
    long long count(long long start, long long end) {
        if (start == 0) {
            return prefix_sum[end];
        }

        return prefix_sum[end] - prefix_sum[start - 1];
    }
    long long solve(int start, int end) {
        if (end - start == 0) {
            return s[start] == '1' ? enc : flat;
        }

        
        long long ans = LLONG_MAX;
        if ((end - start + 1) % 2 == 0) {
            long long mid = (start + end) / 2;
            ans = solve(start, mid) + solve(mid + 1, end);
        }

        long long curr = count(start, end);
        long long curr_cost =
            (curr == 0) ? flat : (end - start + 1) * curr * enc;

        return  min(curr_cost, ans);
    }
    long long minCost(string s, int encCost, int flatCost) {
        this->s = s;
        flat = flatCost;
        enc = encCost;
        prefix_sum.assign(s.size(), 0);
        long long counter = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                counter++;
            }
            prefix_sum[i] = counter;
        }
        

        return solve(0, s.size() - 1);
    }
};