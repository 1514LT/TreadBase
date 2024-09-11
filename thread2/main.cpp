#include "Base.hpp"
#include "ThreadBase.hpp"

class A: public ThreadBase
{
public:
  A();
  ~A();
public:
  void run();
};

A::A()
{
}

A::~A()
{
}

void A::run()
{
  while (_running)
  {
    std::cout << "A thread: " << std::this_thread::get_id() << " is running\n";
    // do something
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
  }
  std::cout << "A thread: " << std::this_thread::get_id() << " is quit\n";
  
}


int main(int argc, char const *argv[])
{
  A a;
  a.start();
  a.detach();
  std::this_thread::sleep_for(std::chrono::seconds(3));
  a.stop();
  return 0;
}
