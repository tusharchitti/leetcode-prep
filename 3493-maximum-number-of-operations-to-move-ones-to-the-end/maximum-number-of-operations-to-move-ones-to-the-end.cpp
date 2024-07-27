class Solution {
public:
    int maxOperations(string s) {
        int ans  = 0 ;
        vector<int> v;
        int curr = 0;
        for(int i=0;i<s.size();i++){
          if(s[i] == '1')
          curr++;
          if(s[i] =='0')
          {
            if(curr!=0)
            v.push_back(curr);
            curr = 0;
          }
        }
          int sz =v.size();
        for(int i=0;i<sz;i++){
            ans = ans +v[i]*(sz-i);
        }
        return ans;
    }
};