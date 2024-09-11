#include "Base.hpp"
#include "Thread.hpp"


int main(int argc, char const *argv[])
{
  printf("enter main\n");
  std::shared_ptr<Thread> t(new Thread());
  t->is_main_thread();
  std::thread(&Thread::funktion1,t).join();
  return 0;
}
