class Solution {
    int min_len(int req2, int req3) {
        if (req2 <= 0 && req3 <= 0) return 0;
        req2 = max(0, req2);
        req3 = max(0, req3);
        
        int ans = 1e9;
        for (int c6 = 0; c6 <= min(req2, req3); ++c6) {
            int rem2 = req2 - c6;
            int rem3 = req3 - c6;
            
            int len3 = (rem3 + 1) / 2;
            int len2 = (rem2 + 2) / 3;
            
            ans = min(ans, c6 + len3 + len2);
        }
        return ans;
    }

    int get_total_min_len(int rq2, int rq3, int rq5, int rq7) {
        return max(0, rq5) + max(0, rq7) + min_len(rq2, rq3);
    }

    int factors[10][4] = {
        {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0},
        {2,0,0,0}, {0,0,1,0}, {1,1,0,0}, {0,0,0,1},
        {3,0,0,0}, {0,2,0,0}                        
    };

    string build(int req2, int req3, int req5, int req7, int length) {
        string ans = "";
        for (int step = 0; step < length; ++step) {
            for (int d = 1; d <= 9; ++d) {
                int nr2 = max(0, req2 - factors[d][0]);
                int nr3 = max(0, req3 - factors[d][1]);
                int nr5 = max(0, req5 - factors[d][2]);
                int nr7 = max(0, req7 - factors[d][3]);
                
                if (get_total_min_len(nr2, nr3, nr5, nr7) <= length - 1 - step) {
                    ans += to_string(d);
                    req2 = nr2; req3 = nr3; req5 = nr5; req7 = nr7;
                    break;
                }
            }
        }
        return ans;
    }

public:
    string smallestNumber(string num, long long t) {
        int r2 = 0, r3 = 0, r5 = 0, r7 = 0;
        long long temp = t;
        
        while (temp % 2 == 0) { r2++; temp /= 2; }
        while (temp % 3 == 0) { r3++; temp /= 3; }
        while (temp % 5 == 0) { r5++; temp /= 5; }
        while (temp % 7 == 0) { r7++; temp /= 7; }
        
        if (temp > 1) return "-1";
        
        size_t idx = num.find('0');
        if (idx != string::npos) {
            num = num.substr(0, idx) + string(num.length() - idx, '1');
        }
        
        int n = num.length();
        
        vector<vector<int>> pref(n + 1, vector<int>(4, 0));
        for (int i = 0; i < n; ++i) {
            int d = num[i] - '0';
            pref[i+1][0] = pref[i][0] + factors[d][0];
            pref[i+1][1] = pref[i][1] + factors[d][1];
            pref[i+1][2] = pref[i][2] + factors[d][2];
            pref[i+1][3] = pref[i][3] + factors[d][3];
        }
        
        if (pref[n][0] >= r2 && pref[n][1] >= r3 && pref[n][2] >= r5 && pref[n][3] >= r7) {
            return num;
        }
        
        for (int i = n - 1; i >= 0; --i) {
            int p2 = pref[i][0], p3 = pref[i][1], p5 = pref[i][2], p7 = pref[i][3];
            int orig_d = num[i] - '0';
            
            for (int d = orig_d + 1; d <= 9; ++d) {
                int nr2 = max(0, r2 - p2 - factors[d][0]);
                int nr3 = max(0, r3 - p3 - factors[d][1]);
                int nr5 = max(0, r5 - p5 - factors[d][2]);
                int nr7 = max(0, r7 - p7 - factors[d][3]);
                
                int rem_len = n - 1 - i;
                if (get_total_min_len(nr2, nr3, nr5, nr7) <= rem_len) {
                    return num.substr(0, i) + to_string(d) + build(nr2, nr3, nr5, nr7, rem_len);
                }
            }
        }
        
        int new_len = max(n + 1, get_total_min_len(r2, r3, r5, r7));
        return build(r2, r3, r5, r7, new_len);
    }
};