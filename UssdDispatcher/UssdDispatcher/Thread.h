// Thread.h: interface for the CThread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREAD_H__C92E35E1_CFA5_11D5_BC7C_80000BD44F70__INCLUDED_)
#define AFX_THREAD_H__C92E35E1_CFA5_11D5_BC7C_80000BD44F70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <process.h>
#include <windows.h>
class CThread {

public:
	void Exit();
	//constructors
	CThread ();

	//destructor
	virtual ~CThread ();

	bool CreateThread (LPVOID pParam = NULL);

	bool IsRunning();
	int	IsCreated ()
	{	return (this->hThread != NULL);	}

	DWORD		Timeout;

	HANDLE	GetThreadHandle ()
	{	return this->hThread;	}
	DWORD	GetThreadId ()
	{	return this->hThreadId;	}
	HANDLE	GetMainThreadHandle ()
	{	return this->hMainThread;	}
	DWORD	GetMainThreadId ()
	{	return this->hMainThreadId;	}

protected:
	struct param {
		CThread*	pThread;
		LPVOID pParam;
	};

	//overrideable
	virtual unsigned long Process (void* parameter);	

	DWORD		hThreadId;
	HANDLE		hThread;
	DWORD		hMainThreadId;
	HANDLE		hMainThread;
    bool        m_bExitThread;
	
private:

	static int runProcess (void* Param);

};


#endif // !defined(AFX_THREAD_H__C92E35E1_CFA5_11D5_BC7C_80000BD44F70__INCLUDED_)
