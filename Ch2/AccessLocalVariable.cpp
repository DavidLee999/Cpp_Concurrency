#include <iostream>
#include <thread>

void do_something(int& i)
{ ++i; }

struct func
{
    int& i;

    func(int& i_) : i { i_ } {}

    void operator () ()
    {
        for (unsigned j = 0; j < 1000000; ++j)
            do_something(i); // dangling reference
    }
};

void oops()
{
    int some_local_state;
    func my_func { some_local_state };
    std::thread my_thread { my_func };

    // my_thread.detach(); // don't wait for thread to finish
    my_thread.join(); // wait until thread finish

    std::cout << some_local_state << "\t" << my_thread.joinable() << std::endl;
}

int main()
{
    oops();
}
