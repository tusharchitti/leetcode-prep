class Foo {
public:
binary_semaphore seconds{0} , thirds{0};
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        seconds.release();
    }

    void second(function<void()> printSecond) {
        seconds.acquire();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        thirds.release();
    }

    void third(function<void()> printThird) {
        
        thirds.acquire();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};