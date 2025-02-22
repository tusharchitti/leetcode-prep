class Solution {
public:

    void checkValidAndInsert(vector<vector<int>>& heights, int x, int y, vector<vector<int>> &neighboring)
    {
        if(!(x<0 || y<0 || x>=heights.size() || y>=heights[0].size()))
        {
            neighboring.push_back({x,y}); 
        }
    }

    vector<vector<int>>  getNeighbougingCells(vector<vector<int>>& heights, int x, int y)
    {
        vector<vector<int>> neighboring;
        checkValidAndInsert(heights,x+1,y,neighboring);
        checkValidAndInsert(heights,x-1,y,neighboring);
        checkValidAndInsert(heights,x,y+1,neighboring);
        checkValidAndInsert(heights,x,y-1,neighboring);
        return neighboring;
    }

    class Comparator
    {
        public:
        bool operator()(vector<int>a , vector<int> b)
        {
              return a[2]>b[2];
        }
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<vector<int> , vector<vector<int>> , Comparator> pqMinEffort;
        vector<vector<int>> minValue(n,vector<int>(m,INT_MAX));
        pqMinEffort.push({0,0,0});
        while(pqMinEffort.size()!=0)
        {
            vector<int> top = pqMinEffort.top();
            pqMinEffort.pop();
            if (top[2] > minValue[top[0]][top[1]]) continue;
            minValue[top[0]][top[1]] = top[2];

            vector<vector<int>> neighbours = getNeighbougingCells(heights, top[0],top[1]);
            for(int index = 0;index <neighbours.size();index++)
            {
                vector<int> neighbour = neighbours[index];
                int diffFromTop = abs(heights[top[0]][top[1]] - heights[neighbour[0]][neighbour[1]]);
                int newEffort = max(top[2], diffFromTop);
                if(newEffort < minValue[neighbour[0]][neighbour[1]])
                {
                    minValue[neighbour[0]][neighbour[1]] = newEffort;
                    pqMinEffort.push({neighbour[0],neighbour[1],newEffort});
                }
            }
        }

        return minValue[n-1][m-1];
    }
};