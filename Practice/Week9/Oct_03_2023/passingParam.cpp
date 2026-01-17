#include <iostream>
#include <thread>
#include <future>
// #include <pthread.h>

int threadFunction(int arg1, std::string arg2)
{
    std::cout << "No : " << arg1 << " : " << arg2 << std::endl;
    return 1;
}

int main()
{
    int param1 = 40;
    std::string param2 = "Shri";
    std::future<int> futureResult = std::async(std::launch::async, threadFunction, param1, param2);
    // std::launch::defered -> run lazily, only when future.get() is called
    // std::launch::aync -> always run in new thread.
    // future cannot be copied only moved
    // std::promise -> way to manually set a value in std::future -> promise is producer, future is consumer

    // std::thread thread1(threadFunction, param1, param2);

    int result = futureResult.get();
    std::cout << result << std::endl;

    // thread1.join();
    return 0;
}