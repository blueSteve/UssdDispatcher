#pragma once
#include "IOCPClientManager.h"
#include "ThreadPool.h"
#include "Thread.h"
class Dispatcher
{
public:
	Dispatcher(void);
	~Dispatcher(void);
private:
	IOCPClientManager m_clnt_mgr;
	ThreadPool m_thread_pool;
	int CreateThreadPool(int num);

	CThread* GetFreeThreadFromPool();

};

