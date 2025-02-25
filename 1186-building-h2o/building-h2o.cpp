class H2O {
public:
    int HCount =0;
    int OCount =0;
    mutex mtx;
    condition_variable cv;
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock1(mtx);

        while(HCount>=2)
        {
            cv.wait(lock1);
        }

        HCount++;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        if(HCount ==2 && OCount ==1)
        {
            HCount = 0;
            OCount = 0;
            cv.notify_all();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock2(mtx);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        while(OCount>=1)
        {
            cv.wait(lock2);
        }
        OCount++;

        releaseOxygen();
        if(HCount ==2 && OCount ==1)
        {
            HCount = 0;
            OCount = 0;
            cv.notify_all();
        }
    }
};