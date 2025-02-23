#include <mutex>
#include <condition_variable>
class Foo {
public:
    
    condition_variable isPrintedCV;
    bool isFirstPrinted = false;
    bool isSecondPrinted = false;
    mutex mtx;
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        isFirstPrinted = true;
        isPrintedCV.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lock1(mtx);
        isPrintedCV.wait(lock1,[&]{return isFirstPrinted;});
        printSecond();
        isSecondPrinted = true;
        isPrintedCV.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> lock2(mtx);
        isPrintedCV.wait(lock2,[&]{return isSecondPrinted;});
        printThird();
    }
};