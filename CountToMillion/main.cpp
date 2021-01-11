#include <string>
#include <iostream>
#include "Counter.h"
#include "ManagedEvent.h"


const std::wstring firstEventName = L"FirstCounterEvent";
const std::wstring secondEventName = L"SecondCounterEvent";

int main() {
	// create the two named events
	ManagedEvent firstEvent(firstEventName, true);
	ManagedEvent secondEvent(secondEventName, false);
	// initialize the shared memory
	DWORD shared = 0;

	Counter firstThread(&shared, 1, firstEvent.getHandle(), secondEvent.getHandle());
	Counter secondTherad(&shared, 2, secondEvent.getHandle(), firstEvent.getHandle());

	return 0;
}