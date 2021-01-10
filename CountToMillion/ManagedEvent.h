#pragma once
#include <string>
#include <Windows.h>
#include "WinAPIException.h"


class ManagedEvent
{
public:
	/*
	 * The constructor - initializes a NamedEvent
	 * Might throw WinAPI exception.
	 *
	 * @param name - the Event's name, as a widestring
	 * @param initialState - true if the Event is signaled at start
	 */
	ManagedEvent(const std::wstring& name, bool initialState);

	// delete copy constructor and copy assignment
	ManagedEvent& operator=(const ManagedEvent& other) = delete;
	ManagedEvent(const ManagedEvent& other) = delete;

	// Return the handle
	HANDLE getHandle() const;
	// The Destructor - closes the handle
	virtual ~ManagedEvent();
private:
	HANDLE m_handle;
};

