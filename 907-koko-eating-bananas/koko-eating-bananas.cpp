class Solution {
public:
    int can_he_eat(int mid,int h,vector<int>& piles){
        long long total=0;
        for(auto &it:piles){
            total+=(it+mid-1)/mid;
        }

        if(total<=h) return 1;
        return 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int mini = *min_element(piles.begin(), piles.end());
        int maxi = *max_element(piles.begin(), piles.end());

        int l=1;
        int r=maxi;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(can_he_eat(mid,h,piles)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            
        }

        return ans;
    }
};