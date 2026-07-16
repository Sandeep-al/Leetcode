class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixgcd(n);
        int max_till_now=INT_MIN;
        for(int i=0;i<n;i++){
            max_till_now=max(max_till_now,nums[i]);
            prefixgcd[i]=gcd(max_till_now,nums[i]);
        }

        sort(prefixgcd.begin(),prefixgcd.end());
        
        long long sum=0;
        int i=0;
        int j=n-1;

        while(i<j){
            sum+=gcd(prefixgcd[i],prefixgcd[j]);
            i++;
            j--;
        }

        return sum;
    }
};