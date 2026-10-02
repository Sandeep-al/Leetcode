class Solution {
public:
    bool check(int l,int r,vector<int>&nums){

        for(int i=l;i<=r;i++){
            for(int j=l;j<=r;j++){
                if(i!=j && (nums[i] & nums[j])!=0){
                    return false;
                }
            }
        }

        return true;
    } //inclusive
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        int l=0;

        for(int r=0;r<n;r++){

            while(!check(l,r,nums)){
                l++;
            }

            ans=max(ans,r-l+1);
        }

        return ans;
    }
};