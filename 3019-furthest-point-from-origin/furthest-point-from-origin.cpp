class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dash=0;
        int left=0;
        int right=0;
        for(auto it:moves){
            if(it=='R') right++;
            else if(it=='L') left++;
            else dash++;
        }

        return max(left,right)+dash-min(left,right);
    }
};