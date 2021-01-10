#pragma once
#include <Windows.h>
#include "WinAPIException.h"


class ManagedThread
{
public:
	ManagedThread(LPTHREAD_START_ROUTINE threadMain, LPVOID param);

	// delete copy contructor and copy assignment
	ManagedThread& operator=(const ManagedThread& other) = delete;
	ManagedThread(const ManagedThread& other) = delete;

	/*
	 * Destructor - waits for the thread to finish using WaitForSingleObject.
	 * Waits infinitly.
	 */
	virtual ~ManagedThread();
private:
	HANDLE m_handle;
};

