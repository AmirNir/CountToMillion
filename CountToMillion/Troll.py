from win32event import CreateEvent, SetEvent

def main():
	"""
	Set the thread's event and interrupt the count.
	"""
	handl = CreateEvent(None, True, True, "FirstCounterEvent")
	SetEvent(handl)
	
if __name__ == '__main__':
	main()