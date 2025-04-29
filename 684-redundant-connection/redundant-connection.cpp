class UnionFind {
    vector<int> parent;

public:
    UnionFind(int size) {
        parent.resize(size+1);
        for (int i = 0; i <= size; ++i)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] != node)
            parent[node] = findParent(parent[node]); // Path compression
        return parent[node];
    }

    void merge(int node1, int node2) {
        int parent1 = findParent(node1);
        int parent2 = findParent(node2);
        if (parent1 != parent2) {
            parent[parent1] = parent2;
        }
    }

    bool isConnected(int node1, int node2) {
        return findParent(node1) == findParent(node2);
    }
};


class Solution {
public:
    
    bool isRedundant(vector<vector<int>>& edges, int ignore)
    {

        // for every ndo echekc if they ar alraeady conencted or not ?
        UnionFind un(edges.size());
        for(int i=0;i<edges.size();i++)
        {
            if(i == ignore) continue;
            if(un.isConnected(edges[i][0],edges[i][1]))
            {
                return false;
            }
            un.merge(edges[i][0],edges[i][1]);
        }

        return true;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         for(int i =edges.size()-1;i>=0;i--)
         {
            if(isRedundant(edges,i))
            {
                return {edges[i][0],edges[i][1]};
            }
         }
         return {-1,-1};
    }
};