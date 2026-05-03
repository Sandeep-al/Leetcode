class Solution {
public:
    bool rotateString(string s, string goal) {
        
       
        if(goal.length()!=s.length() ){
            return false;
        }
         s=s+s;
        if(s.find(goal) != string::npos){
            return true;
        }

        return false;

       
    }
};