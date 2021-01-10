#pragma once
#include "ManagedThread.h"

DWORD WINAPI counterMain(LPVOID param);

class Counter : ManagedThread
{
public:
	/*
	 * The Constructor
	 * Will initialize a Managed thread with main function 'counterMain'.
	 * it will pass itself as parameter.
	 * might throw WinAPI excpetion.
	 *
	 * @param m_shared - A pointer to the shared buffer that contains the last printed message
	 * @param m_counter - The current therad's counter
	 * @param m_readyEvent - A handle of the NamedEvent object that this thread will wait for
	 */
	Counter(LPDWORD shared,
			DWORD counter,
			HANDLE readyEvent,
			HANDLE otherThreadEvent
			);

	// Getters and setters
	DWORD getShared() const;
	void SetShared(DWORD shared);
	DWORD getCounter() const;
	void SetCounter(DWORD shared);
	HANDLE getReadyEvent() const;
	HANDLE getOtherThreadEvent() const;

private:
	// A pointer to the shared buffer that contains the last printed message
	LPDWORD m_shared;
	// The current therad's counter 
	DWORD m_counter;
	// A handle of the NamedEvent object that this thread will wait for
	HANDLE m_readyEvent;
	// A handle of the NamedEvent object that the other thread will wait for
	HANDLE m_otherThreadEvent;
};

