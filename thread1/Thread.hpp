#ifndef THREAD_HPP
#define THREAD_HPP
#include "Base.hpp"

class Thread
{
private:
  std::thread::id main_thread_id;
public:
  Thread();
  ~Thread();
public:
  void is_main_thread();
  void funktion1();
};


#endif