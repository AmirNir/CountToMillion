#pragma once
#include "ManagedThread.h"
#include "SharedObject.h"

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
	 * @param m_shared - A refrence to the shared memory object.
	 * @param m_counter - The current therad's counter
	 * @param m_readyEvent - A handle of the NamedEvent object that this thread will wait for
	 */
	Counter(SharedObject& shared,
			DWORD counter,
			HANDLE readyEvent,
			HANDLE otherThreadEvent
			);

	// Getters and setters
	DWORD getShared() const;
	void SetShared(DWORD shared);
	DWORD getCounter() const;
	void SetCounter(DWORD counter);
	HANDLE getReadyEvent() const;
	HANDLE getOtherThreadEvent() const;

private:
	// A refrence to the shared memory location.
	SharedObject& m_shared;
	// The current therad's counter 
	DWORD m_counter;
	// A handle of the NamedEvent object that this thread will wait for
	HANDLE m_readyEvent;
	// A handle of the NamedEvent object that the other thread will wait for
	HANDLE m_otherThreadEvent;
};

