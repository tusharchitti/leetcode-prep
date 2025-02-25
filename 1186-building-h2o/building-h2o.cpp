#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class H2O {
private:
    int hydrogenCount = 0;  // Track hydrogen threads
    int oxygenCount = 0;    // Track oxygen threads
    mutex mtx;
    condition_variable cv;

public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        
        // Wait until there are fewer than 2 hydrogen threads
        while (hydrogenCount >= 2) {
            cv.wait(lock);
        }

        hydrogenCount++;

        // Release Hydrogen molecule
        releaseHydrogen();

        // If we have 2 H and 1 O, signal threads to proceed
        if (hydrogenCount == 2 && oxygenCount == 1) {
            hydrogenCount = 0;
            oxygenCount = 0;
            cv.notify_all();  // Allow the next set of threads
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);

        // Wait until there is less than 1 oxygen thread
        while (oxygenCount >= 1) {
            cv.wait(lock);
        }

        oxygenCount++;

        // Release Oxygen molecule
        releaseOxygen();

        // If we have 2 H and 1 O, signal threads to proceed
        if (hydrogenCount == 2 && oxygenCount == 1) {
            hydrogenCount = 0;
            oxygenCount = 0;
            cv.notify_all();  // Allow the next set of threads
        }
    }
};
