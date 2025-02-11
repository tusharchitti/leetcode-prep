class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        // 600 ,640
        vector<string> ans;
        map<string, vector<int>> mp;
        int len = keyName.size();
        for(int i=0;i<len;i++)
        {
             int index = keyTime[i].find(':');
             int hours = stoi(keyTime[i].substr(0,index));
             int minutes = stoi(keyTime[i].substr(index+1,keyTime[i].length()-index-1));
             int total = hours*60+minutes;
             
             if(mp.find(keyName[i]) == mp.end())
             {
                 mp[keyName[i]] = {};
             }
             
             mp[keyName[i]].push_back(total);
        }
        map<string, vector<int>>::iterator it;
        for(it =mp.begin();it!= mp.end();it++)
        {

            sort((it->second).begin(), (it->second).end());
        }

        for(it =mp.begin();it!= mp.end();it++)
        {
            vector<int> vp = it->second;
            //
            for(int j=0;j<vp.size();j++)
            {
                cout<<vp[j]<<" ";
            }
            cout<<endl;
            for(int j=2;j<vp.size();j++)
            {
                if(vp[j]-vp[j-2] <=60)
                {
                    ans.push_back(it->first);
                    break;
                }
            }
        }
        return ans;
    }
};