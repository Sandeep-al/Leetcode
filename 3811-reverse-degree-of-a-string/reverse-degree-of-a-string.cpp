class Solution {
public:
    int reverseDegree(string s) {
        int cost=0;
        int i=1;
        for(auto &it:s){
            int curr=int('z')-int(it)+1;
            cost+=(curr*i);
            i++;

        }
        return cost;
    }
};