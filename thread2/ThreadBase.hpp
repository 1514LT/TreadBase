#ifndef THREADBASE_HPP
#define THREADBASE_HPP
#include "Base.hpp"

class ThreadBase
{
private:
  
public:
  ThreadBase();
  ~ThreadBase();
public:
  bool start();
  void stop();
  bool isAlive() const;
  std::thread::id id();
  std::thread* getThread();
  void join();
  void detach();
  static size_t CURRENT_THREADID();

protected:
  static void threadEntry(ThreadBase *pThread);
  virtual void run() = 0;
protected:
  bool _running;
  std::thread* _th;
};



#endif