class ZeroEvenOdd {
private:
    int n;
    int cur_val;         // Tracks the current number
    mutex mx;            // Mutex for synchronization
    condition_variable cv; // Condition variable for signaling
    int turn;            // Tracks whose turn it is (1: zero, 2: odd, 3: even)

public:
    ZeroEvenOdd(int n) : n(n), cur_val(1), turn(1) {}

    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            unique_lock<mutex> lck(mx);
            cv.wait(lck, [this]() { return turn == 1; });
            printNumber(0);  // Print zero
            turn = (cur_val % 2 == 0) ? 3 : 2; // Switch to even or odd
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lck(mx);
            cv.wait(lck, [this]() { return turn == 3; });
            printNumber(cur_val++);  // Print even number
            turn = 1;  // Switch back to zero
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lck(mx);
            cv.wait(lck, [this]() { return turn == 2; });
            printNumber(cur_val++);  // Print odd number
            turn = 1;  // Switch back to zero
            cv.notify_all();
        }
    }
};