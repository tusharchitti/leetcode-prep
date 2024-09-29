class Solution {
public:
    bool isvalid(vector<int>& prefix, vector<int>& count) {
    for (int i = 0; i < 26; i++) {
        if (prefix[i] < count[i]) {
            return false;
        }
    }
    return true;
}
    long long validSubstringCount(string word1, string word2) {
        vector<int>count(26,0);
        for(int i=0;i<word2.size();i++){
            count[word2[i]-'a']++;
        }
        long long ans=0;
        int i=0;
        int j=0;
        int n=word1.size();
        int m=word2.size();
        vector<int>prefix(26,0);
        while(i<n){
            prefix[word1[i]-'a']++;
            while(isvalid(prefix,count)&&j<=i){
                ans+=n-i;
                prefix[word1[j]-'a']--;
                j++;
            }
            i++;
        }
        return ans;
    }
};