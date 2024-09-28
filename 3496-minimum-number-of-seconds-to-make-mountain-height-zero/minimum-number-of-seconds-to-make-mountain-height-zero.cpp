class Solution {
public:
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        //our priority queue will be containing three elements -> cost,height decresed by it,workerTimes
        priority_queue<pair<long long,pair<long long,long long>>,vector<pair<long long,pair<long long,long long>>>,greater<pair<long long,pair<long long,long long>>>> pq;
        //min heap
        for(long long i = 0;i < wt.size();i++){
            pq.push({wt[i],{1,wt[i]}});
        }
        long long maxi = -1e17;
        //ek step aage tak karna hoga
        long long  cost = 0;
        while(mh){
            auto t = pq.top();
            pq.pop();
            mh--;
            if(mh <= 0){
                return 1ll*t.first;
            }
            // ek step extra karne par hi minimum ka pata chal raha hai
            long long height = t.second.first+1;
            //meter of mountain
            long long work = t.second.second;
            //change cost
            
            cost = work*(height)*(height+1)/2;//this is time
            pq.push({cost,{height,work}});
        }
        return 0;
    }
};