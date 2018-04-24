#include <thread>
#include <utility>
#include <iostream>

class scoped_thread
{
    private:
        std::thread t;

    public:
        explicit scoped_thread(std::thread t_) : t { std::move(t_) }
        {
            if (!t.joinable())
                throw std::logic_error("No thread");
        }

        ~scoped_thread()
        {
            t.join();
        }

        scoped_thread(scoped_thread const&) = delete;
        scoped_thread& operator = (scoped_thread const&) = delete;
};

void do_something(int& i)
{ ++i; }

struct func
{
    int& i;
    func(int& i_) : i { i_ } {}

    void operator () ()
    {
        std::cout << "here\n";
        for (unsigned j = 0; j < 1000000; ++j)
            do_something(i);
    }
};

void do_something_in_current_thread()
{}

void f()
{
    int some_local_state = 0;
    std::thread tmp { func{ some_local_state } };
    // tmp.join();
    scoped_thread t { std::move(tmp) };
    do_something_in_current_thread();

    std::cout << some_local_state;
}

int main()
{
    f();
}
