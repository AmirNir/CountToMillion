#include <string>
#include <iostream>
#include "Counter.h"
#include "ManagedEvent.h"
#include "SharedObject.h"

const std::wstring firstEventName = L"FirstCounterEvent";
const std::wstring secondEventName = L"SecondCounterEvent";
const std::wstring sharedMutexName = L"SharedMutex";


int main() {
	
	// create the two named events
	ManagedEvent firstEvent(firstEventName, true);
	ManagedEvent secondEvent(secondEventName, false);

	// initialize the shared memory
	SharedObject shared(0, sharedMutexName);

	Counter firstThread(shared, 1, firstEvent.getHandle(), secondEvent.getHandle());
	Counter secondTherad(shared, 2, secondEvent.getHandle(), firstEvent.getHandle());
	
	return 0;
}