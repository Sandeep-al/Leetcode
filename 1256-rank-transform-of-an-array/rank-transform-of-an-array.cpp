class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> coords = arr;

        sort(coords.begin(), coords.end());

        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        unordered_map<int, int> mp;

        for (int i = 0; i < coords.size(); i++)
            mp[coords[i]] = i;

        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]]+1;
        }

        return arr;
    }
};