#include "ThreadBase.hpp"

ThreadBase::ThreadBase():_running(false),_th(NULL)
{
}

ThreadBase::~ThreadBase()
{
  if(_th != NULL)
  {
    if(_th->joinable())
    {
      _th->detach();
    }
    delete _th;
    _th = NULL;
  }
  _running = false;
  std::cout << "~ThreadBase()" << std::endl;
}


std::thread::id ThreadBase::id()
{
  return _th->get_id();
}
std::thread* ThreadBase::getThread()
{
  return _th;
}

bool ThreadBase::start()
{
  if(_running)
  {
    return false;
  }
  try
  {
    _th = new std::thread(&ThreadBase::threadEntry,this);
  }
  catch(...)
  {
    throw "[ThreadBase::start] thread start error";
  }
  return true;
}

void ThreadBase::stop()
{
  _running = false;
}
bool ThreadBase::isAlive() const
{
  return _running;
}
void ThreadBase::join()
{
  if(_th->joinable())
  {
    _th->join();
  }
}

void ThreadBase::detach()
{
  _th->detach();
}

size_t ThreadBase::CURRENT_THREADID()
{
  static thread_local size_t threadId = 0;
  if(threadId == 0)
  {
    std::stringstream iss;
    iss << std::this_thread::get_id();
    threadId = strtol(iss.str().c_str(),NULL,0);
  }
  return threadId;
}

void ThreadBase::threadEntry(ThreadBase *pThread)
{
  pThread->_running = true;
  try
  {
    pThread->run();
  }
  catch(const std::exception& e)
  {
    pThread->_running = false;
    throw e;
  }
  catch(...)
  {
    pThread->_running = false;
    throw;
  }
  pThread->_running = false;

}