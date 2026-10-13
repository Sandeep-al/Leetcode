class Solution {
public:
    long long kids(int x, vector<int>& candies) {

        long long count = 0;
        for (int i = 0; i < candies.size(); i++) {
            count += candies[i] / x;
        }

        return count;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(),0LL);
        if (sum < k) {
            return 0;
        }

        sort(candies.begin(),candies.end());
        int lo=0;
        int hi=candies[candies.size()-1]+1;

        while(hi-lo>1){
            int mid=(hi-lo)/2+lo;

            if(kids(mid,candies)>=k){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }

        return lo;
    }
};