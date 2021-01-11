#include "Counter.h"
#include <iostream>


constexpr int maxNum = 1000000;
constexpr DWORD sleepTime = 1000;

DWORD WINAPI counterMain(LPVOID param)
{
	Counter* current = static_cast<Counter*>(param);
	HANDLE readyEvent = current->getReadyEvent();
	DWORD counter = current->getCounter();
	// TODO: finish counter logic
	while (counter <= maxNum) {
		WaitForSingleObject(readyEvent, INFINITE);
		// Reset the current thread's event
		ResetEvent(readyEvent);

		if (current->getShared() >= counter) {
			std::cout << "Resetting!" << std::endl;
			counter = 0;
		}

		// Print the current counter
		std::cout << counter << std::endl;

		// Update the shared pointer
		current->SetShared(counter);

		// Increase the counter
		counter += 2;
		current->SetCounter(counter);

		// Sleep for a second
		Sleep(sleepTime);
		
		// Signal the other thread
		if (SetEvent(current->getOtherThreadEvent()) == 0) {
			throw WinAPIException(GetLastError());
		}
	}
	return 0;
}

Counter::Counter(LPDWORD shared, DWORD counter, HANDLE readyEvent, HANDLE otherThreadEvent) : m_shared(shared), m_counter(counter), 
																							  m_readyEvent(readyEvent), m_otherThreadEvent(otherThreadEvent),
																							  ManagedThread(&counterMain, this)
{
	// left blank intentionally
}

DWORD Counter::getShared() const
{
	return *m_shared;
}

void Counter::SetShared(DWORD shared)
{
	*m_shared = shared;
}

DWORD Counter::getCounter() const
{
	return m_counter;
}

void Counter::SetCounter(DWORD counter)
{
	m_counter = counter;
}

HANDLE Counter::getReadyEvent() const
{
	return m_readyEvent;
}

HANDLE Counter::getOtherThreadEvent() const
{
	return m_otherThreadEvent;
}
