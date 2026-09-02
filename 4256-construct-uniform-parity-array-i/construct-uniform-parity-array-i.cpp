class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //odd - odd = even
        //even- even 2k1-2k2 = even
        //odd - even 2k1+1-2K2 = odd
        //even- odd = odd

        //2k+1-2k-1
        //2(k1-k2)

        //id i want to construct all even that means all should be 
        //even or if current number is odd
        // there must be one more odd other than it 
        // that means either all even or some even + atleast one odd

        // to construct all odd similarly
        // i want all odd or some odd and atleast one even

        int odd_count=0;
        int even_count=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                even_count++;
            }
            else{
                odd_count++;
            }
        }
        int n= nums1.size();

        return even_count>=1 || odd_count>=1 || odd_count==n || even_count==n;
    }
};