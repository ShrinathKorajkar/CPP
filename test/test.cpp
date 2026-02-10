#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<chrono>
 
 
std::mutex m;
std::condition_variable cv;
std::queue<int> q;
bool done = false;
 
void producer(){
    for(int i = 0; i<5; i++){
        {
        std::lock_guard<std::mutex> lock(m);
        q.push(i);
        std::cout<<"Produced: "<<i<<std::endl;
        }
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    cv.notify_one();
 
}
 
{
    std::lock_guard<std::mutex> lock(m);
    done = true;
}
 
cv.notify_one();
}
 
void Consumer(){
    while(true){
        std::unique_lock<std::mutex> lock(m);
 
        cv.wait(lock, []{
            return !q.empty() || done;
        });
 
        if(!q.empty()){
            int val = q.front();
            q.pop();
            std::cout<<"Consumed: "<<val<<std::endl;
 
        }
        else if(done){
            break;
        }
    }
    std::cout<<"Consumer exiting.."<<std::endl;
}
 
int main(){
    std::thread t1(producer);
    std::thread t2(Consumer);
 
    t1.join();
    t2.join();
 
    return 0;
}