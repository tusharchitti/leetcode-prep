class Solution {
public:
    vector<string> vectorToString(string domains)
    {
        vector<string> ans;
        int len = domains.length();
        int prev = len;
        for(int i=domains.length();i>=0;i--)
        { 
           if(domains[i] == '.')
           {
             //set substring
             string s = domains.substr(i+1, len-i-1);
             ans.push_back(s);
           }
        }
        ans.push_back(domains);
        return ans;
    }

    pair<int, string> breakIt(string domain)
    {
        int num = 0;
        string s = "";
        bool isNum = true;
        for(int i=0;i<domain.length();i++)
        {
            if(domain[i] == ' ')
            {
                isNum = false;
                continue;
            }
            if(isNum)
            {
                num = num*10 + (domain[i] - '0');
            }
            else
            {
                s= s+domain[i];
            }
        }
        return make_pair(num,s);
    }

    vector<string> domainToString(map<string,int>mp)
    {
        vector<string> ans;
        map<string, int>::iterator it;
        for(it = mp.begin(); it != mp.end();it++)
        {
            string s = to_string(it->second) + ' ' + it->first;
            ans.push_back(s);
        }
        return ans;
    }

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string , int> mp;
        for(int i=0;i<cpdomains.size();i++)
        {
            pair<int,string> pr = breakIt(cpdomains[i]);
            vector<string> domains = vectorToString(pr.second);
            for(int i=0;i<domains.size();i++)
            {
               mp[domains[i]] = mp[domains[i]] + pr.first;
            }
        }
        return domainToString(mp);
    }
};