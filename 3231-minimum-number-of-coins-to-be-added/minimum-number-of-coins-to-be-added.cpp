class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end()); 
        
        long long obtained = 0; 
        int added = 0;          
        int index = 0;          
        
        while (obtained < target) {
           
            if (index < coins.size() && coins[index] <= obtained + 1) {
                obtained += coins[index];
                index++;
            }
            
            else {
                
                obtained += (obtained + 1);
                added++;
            }
        }
        
        return added;
    }
};