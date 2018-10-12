// Thread.cpp: implementation of the CThread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Thread.h"

//*********************************************************
//default constructor for class CThread
//*********************************************************
CThread::CThread ()
{
	this->hThread		= NULL;
	this->hThreadId		= 0;
	this->hMainThread	= ::GetCurrentThread ();
	this->hMainThreadId = ::GetCurrentThreadId ();
	this->Timeout		= 200; //milliseconds
    m_bExitThread = false;
}

//*********************************************************
//destructor for class CObject
//*********************************************************
CThread::~CThread ()
{
	//waiting for the thread to terminate
	if (this->hThread) {
		if (::WaitForSingleObject (this->hThread, this->Timeout) == WAIT_TIMEOUT)
			::TerminateThread (this->hThread, 1);

		::CloseHandle (this->hThread);
        this->hThread = NULL;
	}
}

//*********************************************************
//working method
//*********************************************************
unsigned long CThread::Process (void* parameter)
{

	//a mechanism for terminating thread should be implemented
	//not allowing the method to be run from the main thread
	if (::GetCurrentThreadId () == this->hMainThreadId)
		return 0;
	else {

		return 0;
	}

}

//*********************************************************
//creates the thread
//*********************************************************
bool CThread::CreateThread (LPVOID pParam)
{

	if (!this->IsCreated ()) {
        m_bExitThread = false;
		param*	this_param = new param;
		this_param->pThread	= this;
		this_param->pParam = pParam;
		this->hThread = (HANDLE)::_beginthreadex(NULL,\
                                            0,\
                            (unsigned int (__stdcall *)(void *))this->runProcess,\
                            (void *)(this_param), \
                            0, \
                            (unsigned int*)&this->hThreadId);
		return this->hThread ? true : false;
	}
	return false;

}

//*********************************************************
//creates the thread
//*********************************************************
int CThread::runProcess (void* Param)
{
	CThread*	thread;
	LPVOID pParam   = NULL;
	thread			= (CThread*)((param*)Param)->pThread;
	pParam          =  ((param*)Param)->pParam;     
	delete	((param*)Param);
	return thread->Process (pParam);
}


void CThread::Exit()
{
    m_bExitThread = true;
    if (this->hThread) 
	{
		if (::WaitForSingleObject (this->hThread, this->Timeout) == WAIT_TIMEOUT)
		{
			::TerminateThread (this->hThread, 1);
		}

		::CloseHandle (this->hThread);
        this->hThread = NULL;
	}
}

bool CThread::IsRunning()
{
	bool bRet = false;
	if(hThread != NULL)
	{
		bRet = (::WaitForSingleObject (hThread, 0) == WAIT_TIMEOUT);
	}
	return bRet;
}
