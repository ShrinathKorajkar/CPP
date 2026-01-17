#include <iostream>
#include <mutex>
#include <thread>

/*
    race condition, producer-consumer implementation

*/

template <typename T>
class custom_lock_guard
{
    T &mtx;

public:
    custom_lock_guard(const T &mtx) : mtx(mtx)
    {
        mtx.lock();
    }

    ~custom_lock_guard()
    {
        mtx.unlock();
    }
};

int main()
{

    return 0;
}