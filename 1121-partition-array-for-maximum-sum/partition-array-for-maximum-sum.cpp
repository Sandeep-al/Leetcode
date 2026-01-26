class Solution {
public:
    int k;
    int n;
    int function(int i, vector<int>& arr,vector<int>&dp) {
        if(i==n) return 0;

        if(dp[i]!=-1){
            return dp[i];
        }
        int range = min(i + k, n);
        int global_maxi = arr[i];
        int arr_maxi = arr[i];

        for (int x = i; x < range; x++) {
            arr_maxi = max(arr_maxi, arr[x]);
            int result = arr_maxi * (x - i + 1) + function(x + 1, arr,dp);
            global_maxi = max(global_maxi, result);
        }

        return dp[i]=global_maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k1) {
        k =k1;
        n = arr.size();
        vector<int>dp(n+1,-1);
        return function(0,arr,dp);
    }
};