class Solution {
public:

    void print(vector<vector<int>> routes)
    {
           
           for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++)
            {
                cout<<routes[i][j]<<" ";
            }
            cout<<endl;
           }
    }

    int minJumpbfs(vector<vector<int>> &r , int curr, int target, vector<int> &visited) {

    queue<pair<int, int>> q;  

    visited[curr] = 1; 
    q.push({curr, 0});   

    while (!q.empty()) {
        int node = q.front().first;   
        int level = q.front().second; 
        q.pop();

        if (node == target) {
            cout<<node <<" :: done :: "<<target<<endl;
            return level; 
        }

        for (int i = 0;i<r[node].size();i++) {
            if (visited[i]==0 && r[node][i]==1) {   
                visited[i] = 1;
                q.push({i, level + 1});
            }
        }
    }
        return -1;
    }
    int getMinJump(vector<vector<int>> &r , int start , int end) {
         vector<int> visit(r.size(),0);
         return minJumpbfs(r,start,end,visit);
    }

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
       if(source == target) return 0;
       int sz = routes.size();
       vector<vector<int>> mp(sz , vector<int>(sz, 0));
       map<int, vector<int>> station; 
       
       for(int i=0;i<routes.size();i++) {
          for(int j=0;j<routes[i].size();j++){
            int st = routes[i][j];
            if(station.find(st)==station.end()) {
                station[st] = vector<int>(sz,0);
            }
            station[st][i] = 1;
          }
       }
       
       for(int i=0;i<routes.size();i++){
        for(int j=0;j<routes[i].size();j++){
            vector<int> tmp = station[routes[i][j]];
            for(int k=0;k<tmp.size();k++){
                if(tmp[k]!=0)
                mp[i][k] =1;
            }
        }
       }

       //print(mp);
       vector<int> s = station[source];
       vector<int> t = station[target];
       int ans = INT_MAX;
       for(int i=0;i<s.size();i++){
        if(s[i] == 0) continue;
        for(int j=0;j<t.size();j++){
            if(t[j] == 0) continue;
            int ta  = getMinJump(mp,i,j);
            if(ta != -1) ans = min(ans,ta);
        }
       }
       if(ans == INT_MAX) return -1;
       return ans+1;
    }
};