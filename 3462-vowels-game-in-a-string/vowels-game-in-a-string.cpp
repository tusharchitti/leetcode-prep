class Solution {
public:
    bool doesAliceWin(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i] =='a' || s[i] =='e' || s[i] =='o' || s[i] =='i' || s[i] =='u'){
             return true;
            }
        }
        return false;
    }
};