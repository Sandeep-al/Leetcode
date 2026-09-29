class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double sum=0;
        double maxi=INT_MIN;
        int n=nums.size();

        for(int i=0;i<n;i++){
            
            sum+=nums[i];

            if(i>=k){
                sum-=nums[i-k];
            }

            if(i>=k-1){
                maxi=max(maxi,sum);
            }
        }

        return maxi/k;
    }
};