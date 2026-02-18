class Solution {
public:
    bool hasAlternatingBits(int n) {
        string chk="";
        while(n>0){
            int x=n&1;
            chk=to_string(x)+chk;
            n>>=1;   
        }
        for(int i=0;i<chk.size()-1;i++){
            if(chk[i]==chk[i+1]) return false;
        }
        return true;
    }
    
};