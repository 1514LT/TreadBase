#include "Thread.hpp"

Thread::Thread()
{
  main_thread_id = std::this_thread::get_id();
}

Thread::~Thread()
{
}

void Thread::is_main_thread()
{
  if ( main_thread_id == std::this_thread::get_id() )
    std::cout << "This is the main thread.\n";
  else
    std::cout << "This is not the main thread.\n";
}

void Thread::funktion1()
{
  std::cout << "funktion1" << std::endl;
  is_main_thread();
}