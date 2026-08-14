class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;

        for(auto &it:nums){
            pq.push(it);
        }

        int i=0;
        while(i<k-1 && !pq.empty()){
            pq.pop();
            i++;
        }

        return pq.top();
    }
};