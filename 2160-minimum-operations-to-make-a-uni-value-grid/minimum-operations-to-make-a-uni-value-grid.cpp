class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>temp;
        for(auto &it:grid){
            for(auto &jt:it){
                temp.push_back(jt);
            }
        }

        sort(temp.begin(),temp.end());
        int n=temp.size();
        int median=temp[n/2];
        int ans=0;
        for(int i=0;i<n;i++){
            int curr= abs(temp[i]-median);
            if((curr % x)!=0){
                return -1;
            }

            ans+=(curr/x);
        }

        return ans;
    }
};