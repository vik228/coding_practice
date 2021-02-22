#include <bits/stdc++.h>
using namespace std;

class FunctionRateLimiter {
private:
    int rate;
    function<void()> func;
    long int lastTimeCalled;
public:
    FunctionRateLimiter(int rate, function<void ()> myfunc) {
        this->rate = rate;
        this->func = myfunc;
        this->lastTimeCalled = -1;
    }

    bool apply() {
        long int current_time = (long int) time(NULL);
        if (this->lastTimeCalled == -1 or (current_time - this->lastTimeCalled) >= rate) {
            this->func();
            this->lastTimeCalled = current_time;
            return true;
        }
        return false;
    }
};

void f() {
    cout << "called\n";
}

int main() {
    FunctionRateLimiter frl(10, f);
    frl.apply();
    frl.apply();
    return 0;
}