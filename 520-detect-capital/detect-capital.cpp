class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allcapital=true;

        for(auto &it:word){
            if(islower(it)){
                allcapital=false;
            }
        }

        bool alllower=true;

        for(auto &it:word){
            if(isupper(it)){
                alllower=false;
            }
        }

        bool onlyfirst=true;

        for(int i=0;i<word.size();i++){
            if(i==0 && islower(word[i])) onlyfirst=false;
            
            else if(i>0){
                if(isupper(word[i])) onlyfirst=false;
            }
        }

        return allcapital || alllower || onlyfirst;
    }
};