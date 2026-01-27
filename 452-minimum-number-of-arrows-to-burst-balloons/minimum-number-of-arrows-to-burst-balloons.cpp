class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const std::vector<int>& a, const std::vector<int>& b) {
                 return a[1] < b[1];
             });

        
        int n=points.size();
        int a=points[0][1];
        int i=0;
        int count=1;
        
        while(i<n){

            if(points[i][0]<=a){
                i++;
            }
            else{
                count++;
                a=points[i][1];
                i++;
            }
        }

         


        return count;
        
    }
};