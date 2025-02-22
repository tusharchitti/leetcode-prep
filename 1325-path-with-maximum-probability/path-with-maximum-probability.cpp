class Solution {
public:
    vector<vector<pair<int,double>>> CreateAdjMat(int n,vector<vector<int>>& edges, vector<double>& succProb)
    {
        vector<vector<pair<int, double>>> adjmat(n);
        for(int i=0;i<edges.size();i++)
        {
            adjmat[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adjmat[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        return adjmat;
    }

    class Comparator
    {
        public:
        bool operator()(pair<int,double> &a, pair<int,double> &b)
        {
            return a.second < b.second ;
        }
    };

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adjmat = CreateAdjMat(n,edges,succProb);
        priority_queue<pair<int,double> , vector<pair<int,double>>, Comparator> pq;
        vector<double> maxProb(n,0);
        pq.push(make_pair(start_node,1.0));
        maxProb[start_node] = 1;
        while(pq.size()!=0)
        {
          pair<int,double> top = pq.top();
          pq.pop();

          vector<pair<int,double>> edges = adjmat[top.first];
          
          for(int index =0; index<edges.size(); index++)
          {
                 double newNumber = edges[index].second * top.second;
                 if(newNumber > maxProb[edges[index].first])
                 {
                   maxProb[edges[index].first] = newNumber;
                   pq.push(make_pair(edges[index].first,newNumber));
                 }
          }

        }
        return maxProb[end_node];
    }
};