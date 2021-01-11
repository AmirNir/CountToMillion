#include "ManagedThread.h"

ManagedThread::ManagedThread(LPTHREAD_START_ROUTINE threadMain, LPVOID param) : m_handle(CreateThread(NULL,
																										0,
																										threadMain,
																										param,
																										0,
																										NULL))
{
	if (m_handle == NULL) {
		throw WinAPIException(GetLastError());
	}
}

ManagedThread::~ManagedThread()
{
	WaitForSingleObject(m_handle, INFINITE);
	CloseHandle(m_handle);
}
