class Solution {
public:

    static bool customComparator( pair<int,map<int,int>> &a, pair<int,map<int,int>> &b) {
        
        map<int,int> am = a.second;;
        map<int,int> bm= b.second;
        //cout<<a.first<<" "<<b.first<<endl;
        if(am.size() == 0) return false;
        if(bm.size() ==0) return true;

        std::map<int, int>::iterator ait = am.begin();
        std::map<int, int>::iterator bit = bm.begin();

        while(ait!=am.end() || bit !=bm.end()) {
            if(ait == am.end() && bit == bm.end()) {
                 cout<<"end here"<<endl;
                 return a.first<b.first; 
            }

            if(ait == am.end()) return false;
            if(bit == bm.end()) return true;

            if(ait->first<bit->first) return true;
            if(ait->first>bit->first)  return false;

            if(ait->first == bit->first) {
                cout<<"dere213"<<endl;
                if(ait->second> bit->second) {
                    return true;
                }else if(ait->second< bit->second) {
                    return false;
                } else {
                    cout<<"dfds11"<<endl;
                    ait++;
                    bit++;
                }
            }
        }
          return a.first<b.first; ;
    }
    string rankTeams(vector<string>& votes) {
        vector<pair<int,map<int,int>>> data;
        
        for(int i=0;i<26;i++){
            data.push_back(make_pair(i, map<int, int>()));
        }

        // brute force 
        for(int i=0;i<votes.size();i++){
            for(int j=0;j<votes[i].size();j++){
                pair<int, map<int,int>> pair = data[votes[i][j]-'A'];
                pair.second[j+1]++;
                data[votes[i][j]-'A'] = make_pair(pair.first , pair.second);
                char c = votes[i][j];
                //cout<<c<<" "<<j+1<<endl;
            }
        }

        for(int i=0;i<data.size();i++){
         cout<<data[i].first<<endl;
         std::map<int, int>::iterator ait = data[i].second.begin();
         while(ait!=  data[i].second.end()) {
              cout<<ait->first<<" :: " <<ait->second<<endl;
              ait++;
         }
         cout<<" -- "<<endl;
        }
        sort(data.begin(), data.end() , customComparator);
        cout<<"dfsd22"<<endl;

        string ans = "";
        for(int i=0;i<data.size();i++){
            if(data[i].second.size() != 0)
            {
            char c = 'A' + data[i].first;
            ans = ans + c;
            }
        }
        return ans;
    }
};