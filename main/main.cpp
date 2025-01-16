
#include <thread>
#include <iostream>
 
thread_local int threadSpecificVar = 0; // 每个线程都有自己的 threadSpecificVar
 
void threadFunction(int id) {
    threadSpecificVar = id; // 设置线程特有的变量
    std::cout << "Thread " << id << ": threadSpecificVar = " << threadSpecificVar;
}
 
int main() {
    std::thread t1(threadFunction, 1);
    std::thread t2(threadFunction, 2);
 
    t1.join();
    t2.join();
 
    return 0;
}