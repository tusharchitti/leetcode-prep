class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        map<string, double> rateMap;
     
        for(int i=0;i<pairs1.size();i++)
        {
            rateMap[pairs1[i][0]] = (double)INT_MIN;
            rateMap[pairs1[i][1]] = (double)INT_MIN;
        }
        rateMap[initialCurrency] = 1;

        int nodes = pairs1.size() + pairs2.size();
        // iterate through map and set initial map ?
        //step one is done;
        for(int i=0;i<nodes;i++)
        {
            for(int j=0;j<pairs1.size();j++)
            {
               // check forward node.
               // pairs1[0]->pairs[i][1]
               if(rateMap[pairs1[j][1]] < rateMap[pairs1[j][0]]*(rates1[j]))
               {
                rateMap[pairs1[j][1]] = rateMap[pairs1[j][0]]*(rates1[j]);
               }

               //  check bakcword node/.
               if(rateMap[pairs1[j][0]] < rateMap[pairs1[j][1]]*(1.0/rates1[j]))
               {
                rateMap[pairs1[j][0]] = rateMap[pairs1[j][1]]*(1.0/rates1[j]);
               }
            }
        }


        for(int i=0;i<pairs2.size();i++)
        {
            if(rateMap.find(pairs2[i][0]) == rateMap.end())
            {
                rateMap[pairs2[i][0]] = INT_MIN;
            }
            if(rateMap.find(pairs2[i][0]) == rateMap.end())
            {
                rateMap[pairs2[i][0]] = INT_MIN;
            }
        }

        // iterate through map and set initial map ?
        //step one is done;
        double ans = 0.0;
        for(int i=0;i<nodes;i++)
        {
            for(int j=0;j<pairs2.size();j++)
            {
               // check forward node.
               // pairs1[0]->pairs[i][1]
               if(rateMap[pairs2[j][1]] < rateMap[pairs2[j][0]]*rates2[j])
               {
                rateMap[pairs2[j][1]] = rateMap[pairs2[j][0]]*rates2[j];
               }

               //  check bakcword node/.
               if(rateMap[pairs2[j][0]] < rateMap[pairs2[j][1]]*(1.0/rates2[j]))
               {
                rateMap[pairs2[j][0]] = rateMap[pairs2[j][1]]*(1.0/rates2[j]);
               }
            }
        }
        
        return rateMap[initialCurrency];

    }
};