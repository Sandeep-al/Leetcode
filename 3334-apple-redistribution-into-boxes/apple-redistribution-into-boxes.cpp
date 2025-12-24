class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total=0;
        for(auto &it:apple){
            total+=it;
        }
        int used=0;
        int i=0;
        sort(capacity.begin(),capacity.end());
        reverse(capacity.begin(),capacity.end());
        while(total!=0){
            total=total-min(total,capacity[i]);
            i++;
        }

        return i;
    }
};