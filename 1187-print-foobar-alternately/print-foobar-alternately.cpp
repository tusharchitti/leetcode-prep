class FooBar {
private:
    int n;
    binary_semaphore printFooSem{1}, printBarSem{0};
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            printFooSem.acquire();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            printBarSem.release();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            printBarSem.acquire();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            printFooSem.release();
        }
    }
};