class Solution {
public:
    int buquets(vector<int>& nums, int k, int days) {

        int total = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > days) {
                curr = 0;
                continue;
            }

            curr++;
            if (curr == k) {
                total++;
                curr = 0;
            }
        }

        

        return total;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n=bloomDay.size();
        
        int lo = 0;
        int x= 1 + *max_element(bloomDay.begin(), bloomDay.end());
        int hi=x;

        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;

            if (buquets(bloomDay, k, mid) >= m) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        if(hi==x) return -1;
        return hi;
    }
};