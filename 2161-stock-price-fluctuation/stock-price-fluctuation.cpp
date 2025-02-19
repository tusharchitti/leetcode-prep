class StockPrice {
public:
    multiset<int> stockPriceSet;
    unordered_map<int,int> stockPriceMap;
    int maxTimestamp;

    StockPrice() {
        maxTimestamp = 0;
    }
    
    void update(int timestamp, int price) {
        if(timestamp > maxTimestamp) 
        {
            maxTimestamp = timestamp;
        }

        if(stockPriceMap.find(timestamp) != stockPriceMap.end())
        {
            stockPriceSet.erase(stockPriceSet.find(stockPriceMap[timestamp]));
        }
        stockPriceSet.insert(price);
        stockPriceMap[timestamp] = price;
    }
    
    int current() {
        return stockPriceMap[maxTimestamp];
    }
    
    int maximum() {
        return *stockPriceSet.rbegin();
    }
    
    int minimum() {
        return *stockPriceSet.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */