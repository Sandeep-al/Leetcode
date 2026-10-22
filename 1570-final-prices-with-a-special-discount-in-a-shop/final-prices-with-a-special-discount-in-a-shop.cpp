class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>next_smaller(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && prices[i]<=prices[st.top()]){
                next_smaller[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        for(int i=0;i<n;i++){
            if(next_smaller[i]!=-1){
                next_smaller[i]=prices[i]-prices[next_smaller[i]];
            }
            else{
                next_smaller[i]=prices[i];
            }
        }

        return next_smaller;
    }
};