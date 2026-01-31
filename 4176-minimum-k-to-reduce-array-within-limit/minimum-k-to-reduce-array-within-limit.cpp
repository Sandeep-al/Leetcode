class Solution {
public:
    bool solve(int k,vector<int>&nums){

        int total=0;
        for(auto &it:nums){
            total+=(it + k - 1) / k;
            if(total > (long long )k*k) return false;
        }

        return total <= (long long)k*k;
    }
    int minimumK(vector<int>& nums) {
        
        int maxi=INT_MIN;
        for(auto &it:nums){
            maxi=max(maxi,it);
        }
        int l=1;
        int h=INT_MAX;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;

            if(solve(mid,nums)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }
};