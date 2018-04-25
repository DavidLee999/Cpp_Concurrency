#include <iostream>
#include <thread>

void do_something(int t)
{
    for (int i = 0; i < t; i++)
        std::cout << std::this_thread::get_id() << "\t" << i << std::endl;
}

int main()
{
    std::thread t { do_something, 100 };
    // t.join();
    // t.detach();
    do_something(5);
    // t.join();
    //t.detach();
    return 0;
}
