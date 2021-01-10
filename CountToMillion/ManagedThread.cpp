#include "ManagedThread.h"

ManagedThread::ManagedThread(LPTHREAD_START_ROUTINE threadMain, LPVOID param) : m_handle(CreateThread(nullptr,
																										0,
																										threadMain,
																										param,
																										0,
																										nullptr))
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
