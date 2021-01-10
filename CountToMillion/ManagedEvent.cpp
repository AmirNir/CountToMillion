#include "ManagedEvent.h"

ManagedEvent::ManagedEvent(const std::wstring& name, bool initialState) : m_handle(CreateEvent( NULL,
																								TRUE,
																								initialState,
																								name.c_str()))
{
	if (m_handle == NULL) {
		throw WinAPIException(GetLastError());
	}
}

HANDLE ManagedEvent::getHandle() const
{
	return m_handle;
}

ManagedEvent::~ManagedEvent()
{
	CloseHandle(m_handle);
}
