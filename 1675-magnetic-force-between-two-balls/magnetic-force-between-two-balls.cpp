class Solution {
public:
    int visited(vector<int>& nums, int x) {
        int i = 0;
        int cnt = 0;
        while (i < nums.size()) {
            cnt++;
            auto it = lower_bound(nums.begin(), nums.end(), nums[i] + x);
            i = it - nums.begin();
        }

        return cnt;
    }
    int maxDistance(vector<int>& position, int m) {
        int lo=0;
        int hi=INT_MAX;
        sort(position.begin(),position.end());
        while(hi-lo>1){
            int mid=(hi-lo)/2+lo;

            if(visited(position,mid)>=m){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }

        return lo;
    }
};