class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0;
        int h=letters.size();

        while(l<h){

            int mid= l+(h-l)/2;

            if(letters[mid]>target){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }

        return letters[l % letters.size()];
    }
};