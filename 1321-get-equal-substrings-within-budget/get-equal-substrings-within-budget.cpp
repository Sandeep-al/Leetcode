class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int l=0;
        int ans=0;
        int cost=0;
        int n=s.size();

        for(int r=0;r<n;r++){
            cost+=abs(int(s[r])-int(t[r]));

            while(cost>maxCost){
                cost-=abs(int(s[l])-int(t[l]));
                l++;
            }

            ans=max(ans,r-l+1);
        }

        return ans;
    }
};