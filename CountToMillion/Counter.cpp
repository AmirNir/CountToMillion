#include "Counter.h"
#include <iostream>


DWORD WINAPI counterMain(LPVOID param)
{
	Counter* current = static_cast<Counter*>(param);
	HANDLE readyEvent = current->getReadyEvent();
	DWORD counter = current->getCounter();
	// TODO: finish counter logic
	while ()
	WaitForSingleObject(readyEvent, INFINITE);
	ResetEvent(readyEvent);

	std::cout << current->getCounter() << std::endl;

	SetEvent(current->getOtherThreadEvent());
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

void Counter::SetCounter(DWORD shared)
{
	m_counter = shared;
}

HANDLE Counter::getReadyEvent() const
{
	return m_readyEvent;
}

HANDLE Counter::getOtherThreadEvent() const
{
	return m_otherThreadEvent;
}
