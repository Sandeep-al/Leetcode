class Solution {
public:
    int invalid(unordered_map<char,int>&mpp){
        int total=0;
        int maxi=0;
        for(auto &it:mpp){
            total+=it.second;
            maxi=max(maxi,it.second);
        } 
        return total-maxi;  //no of characters need to be changed//
    }
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mpp;

        int l=0;
        int ans=0;

        for(int r=0;r<n;r++){
            mpp[s[r]]++;

            while(invalid(mpp)>k){
                mpp[s[l]]--;
                l++;
            }

            ans=max(ans,r-l+1);
        }

        return ans;
    }
};