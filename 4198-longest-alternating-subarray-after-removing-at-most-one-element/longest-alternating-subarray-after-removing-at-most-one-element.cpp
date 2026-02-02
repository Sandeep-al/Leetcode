#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // Helper to get sign: -1 for negative, 1 for positive, 0 for equal
    int getSign(int diff) {
        if (diff > 0) return 1;
        if (diff < 0) return -1;
        return 0;
    }

    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n; // If 0 or 1 elements, answer is n

        // ---------------------------------------------------------
        // 1. Compute Left (Prefix) Array
        // L[i] = Length of alternating subarray ENDING at i
        // ---------------------------------------------------------
        vector<int> L(n, 1);
        for (int i = 1; i < n; i++) {
            int currDiff = nums[i] - nums[i-1];
            
            if (currDiff != 0) { // Must be strictly alternating
                // If the previous subarray has length 1, we just started a sequence (length 2)
                if (L[i-1] == 1) {
                    L[i] = 2;
                } else {
                    // Check if current direction is opposite to previous direction
                    int prevDiff = nums[i-1] - nums[i-2];
                    if (getSign(currDiff) != getSign(prevDiff)) {
                        L[i] = L[i-1] + 1;
                    } else {
                        // Same direction twice (e.g., 1 < 2 < 3) -> Reset to 2 (2 < 3)
                        L[i] = 2; 
                    }
                }
            }
        }

        // ---------------------------------------------------------
        // 2. Compute Right (Suffix) Array
        // R[i] = Length of alternating subarray STARTING at i
        // ---------------------------------------------------------
        vector<int> R(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            int currDiff = nums[i] - nums[i+1]; // Looking rightwards
            
            if (currDiff != 0) {
                if (R[i+1] == 1) {
                    R[i] = 2;
                } else {
                    // Check if current direction is opposite to next direction
                    int nextDiff = nums[i+1] - nums[i+2];
                    if (getSign(currDiff) != getSign(nextDiff)) {
                        R[i] = R[i+1] + 1;
                    } else {
                        R[i] = 2;
                    }
                }
            }
        }

        // ---------------------------------------------------------
        // 3. Calculate Max Length (Removing at most 1 element)
        // ---------------------------------------------------------
        
        // Base Answer: The max length if we DON'T remove anything
        int maxLen = 0;
        for (int x : L) maxLen = max(maxLen, x);

        // Try removing every index 'i' from 1 to n-2
        for (int i = 1; i < n - 1; i++) {
            
            // The elements we are trying to connect are nums[i-1] and nums[i+1]
            int newDiff = nums[i+1] - nums[i-1];
            
            if (newDiff == 0) continue; // Cannot have equal elements

            bool leftCompatible = true;
            bool rightCompatible = true;

            // CHECK LEFT Compatibility
            // If L[i-1] > 1, we must ensure 'newDiff' opposes the previous step
            if (L[i-1] > 1) {
                int prevDiff = nums[i-1] - nums[i-2];
                if (getSign(newDiff) == getSign(prevDiff)) {
                    leftCompatible = false;
                }
            }

            // CHECK RIGHT Compatibility
            // If R[i+1] > 1, we must ensure 'newDiff' opposes the next step
            // Note: R[i+1] calculated diff as (nums[i+1] - nums[i+2]) which is 'nextDiff' from our perspective
            // But wait, my R logic used (current - next). 
            // Let's think simply: The sequence is ... nums[i-1], nums[i+1], nums[i+2] ...
            // The first link is (nums[i+1] - nums[i-1]).
            // The second link is (nums[i+2] - nums[i+1]).
            // These two must have opposite signs.
            if (R[i+1] > 1) {
                int nextLinkDiff = nums[i+2] - nums[i+1];
                if (getSign(newDiff) == getSign(nextLinkDiff)) {
                    rightCompatible = false;
                }
            }

            if (leftCompatible && rightCompatible) {
                maxLen = max(maxLen, L[i-1] + R[i+1]);
            }
        }

        return maxLen;
    }
};