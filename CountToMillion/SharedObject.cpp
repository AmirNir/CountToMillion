#include "SharedObject.h"


SharedObject::SharedObject(DWORD obj, const std::wstring& name) : m_obj(obj), m_objMutex(CreateMutex(NULL,
																											FALSE,
																											name.c_str()
																											))
{
	// check if mutex creation succeeded
	if (m_objMutex == NULL) {
		throw WinAPIException(GetLastError());
	}
}

DWORD SharedObject::getValue() const
{
	// copy the object after getting the mutex.
	WaitForSingleObject(m_objMutex, INFINITE);
	DWORD retval = m_obj;
	ReleaseMutex(m_objMutex);

	return retval;
}

void SharedObject::setValue(DWORD newVal)
{
	WaitForSingleObject(m_objMutex, INFINITE); 
	m_obj = newVal;
	ReleaseMutex(m_objMutex);
	
}

SharedObject::~SharedObject()
{
	CloseHandle(m_objMutex);
}
