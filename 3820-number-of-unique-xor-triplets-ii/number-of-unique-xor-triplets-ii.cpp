class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>st,st1;
        for(auto &it:nums){
            for(auto &jt:nums){
                st.insert(it^jt);
            }
        }

        for(auto &it:st){
            for(auto &jt:nums){
                st1.insert(it^jt);
            }
        }
        return st1.size();


    }
};