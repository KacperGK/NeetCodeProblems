#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<int> data_queue;
std::mutex mtx;
std::condition_variable cv;

void producer(int n){
    for(int i = 0; i < n; ++i){
        int data= i + 1; // simulation of data
    {
        std::unique_lock<std::mutex> lock(mtx); // lock the mutex
        data_queue.push(data); // add data to queue
        std::cout << "Produced: " << data << std::endl;
    } // Mutex is automatically unlocked when lock goes out of scope

    // notify costumer that data is ready
    cv.notify_one();

    //simulated delay sleep for 500 ms
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    }
}

// Consumer function
void consumer(int n){
    for(int i = 0; i < n; ++i){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !data_queue.empty();});

        int data = data_queue.front();
        data_queue.pop();
        std::cout << "Consumed: " << data <<std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}


int main(){
    const int numItems = 6;

    std::thread producerThread(producer,numItems);
    std::thread consumerThread(consumer,numItems);

    producerThread.join();
    consumerThread.join();


    return 0;
}