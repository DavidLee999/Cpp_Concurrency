#include <vector>
#include <future>
#include <iostream>
#include <thread>
#include <numeric>

void accumulate(std::vector<int>::iterator first, std::vector<int>::iterator last, std::promise<int> accumulate_pomise)
{
    int sum = std::accumulate(first, last, 0);
    accumulate_pomise.set_value(sum);
}

int main()
{
    std::vector<int> numbers { 1, 2, 3, 4, 5, 6 };
    std::promise<int> accumulate_pomise;
    std::future<int> accumulate_future = accumulate_pomise.get_future();
    
    std::thread t1 { accumulate, numbers.begin(), numbers.end(), std::move(accumulate_pomise) };
    // accumulate_future.wait();
    // std::cout << "result = " << accumulate_future.get() << std::endl;
    std::cout << "accumulate_future is valid? " << accumulate_future.valid() << std::endl;

    t1.join();
    // std::cout << "t1 joined." << std::endl;

}
