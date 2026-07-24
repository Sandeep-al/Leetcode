class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n,0);
        prefix[0]=((nums[0]%2)==0)?0:1;

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+(((nums[i]%2)==0)?0:1);
        }

        unordered_map<int,int>mpp;
        mpp[0]=1;
        
        int count=0;
        
        for(int r=0;r<n;r++){
            if(mpp.find(prefix[r]-k)!=mpp.end()){
                count+=mpp[prefix[r]-k];
            }
            mpp[prefix[r]]++;
        }
        return count;
    }
};