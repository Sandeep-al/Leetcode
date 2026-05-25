class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        
        // If the last character isn't '0', it's impossible.
        if (s[n - 1] != '0') return false;

        vector<bool> dp(n, false);
        vector<int> diff(n + 1, 0); // This will track our jump ranges
        
        dp[0] = true;
        
        // From index 0, cast our first jump net into the future
        if (minJump < n) diff[minJump] += 1;
        if (maxJump + 1 < n) diff[maxJump + 1] -= 1;

        int active_jumps = 0; // Running sum of valid landing spots

        for (int i = 1; i < n; i++) {
            // Add any start (+1) or end (-1) boundaries we just stepped on
            active_jumps += diff[i];

            // If we are on a '0' AND we are inside at least one valid jump window
            if (s[i] == '0' && active_jumps > 0) {
                dp[i] = true;
                
                // Since this is a valid spot, cast a NEW net into the future!
                if (i + minJump < n) diff[i + minJump] += 1;
                if (i + maxJump + 1 < n) diff[i + maxJump + 1] -= 1;
            }
        }

        return dp[n - 1];
    }
};