#pragma once
#include <string>
#include <Windows.h>
#include "WinAPIException.h"


/*
 * This class represents a shared object.
 * It uses a mutex to make sure only on thread can access it.
 *
 */
class SharedObject
{
public:
	/*
	 * The constructor - initiazes obj, and creates the mutex.
	 * 
	 * @param obj - the object to copy
	 * @param name - the mutex's name
	 */
	SharedObject(DWORD obj, const std::wstring& name);

	/*
	 * The shared value getter. This fucntion waits for the mutex to be signaled.
	 *
	 * @return - The shared value
	 */
	DWORD getValue() const;

	/*
	 * The shared value setter. This fucntion waits for the mutex to be signaled.
	 *
	 * @param newVal - The new shared value
	 */
	void setValue(DWORD newVal);

	// Rule of 3 - delete copy assignment and copy ctor.
	SharedObject& operator=(const SharedObject& other) = delete;
	SharedObject(const SharedObject& other) = delete;

	/*
	 * The destructor. Releses the mutex handle.
	 */
	~SharedObject();
private:
	// The shared object.
	DWORD m_obj;
	// The mutex that is used to synconize access to the shared object.
	HANDLE m_objMutex;
};