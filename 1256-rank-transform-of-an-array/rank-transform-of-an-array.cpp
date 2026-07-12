class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans=arr;
        sort(ans.begin(),ans.end());
        if(arr.size()==0) return {};
        unordered_map<int,int>mpp;

        int rank=1;
        int prev=ans[0];
        for(int i=0;i<ans.size();i++){
            if(ans[i]>prev){
                rank++;
            }

            mpp[ans[i]]=rank;
            prev=ans[i];
        }

        vector<int>final_ans;

        for(int i=0;i<arr.size();i++){
            final_ans.push_back(mpp[arr[i]]);
        }

        return final_ans;

        
    }
};