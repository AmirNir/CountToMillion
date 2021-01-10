#include <string>
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

	Counter(&shared, 0, firstEvent.getHandle(), secondEvent.getHandle());
	Counter(&shared, 1, secondEvent.getHandle(), firstEvent.getHandle());

	return 0;
}