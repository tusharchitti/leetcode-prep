class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> timeModuluesCountMap;
        for(int index = 0;index<time.size();index++)
        {
            timeModuluesCountMap[time[index]%60] ++;
        }
        long int ans = 0;
        for(int index = 0;index<time.size();index++)
        {
            int currentMod= time[index]%60;
            int remaingMod = (60 -  currentMod)%60;
            if(currentMod == remaingMod){
            ans--;    
            }
            ans = ans + timeModuluesCountMap[remaingMod];

        }
        return ans/2;
    }
};