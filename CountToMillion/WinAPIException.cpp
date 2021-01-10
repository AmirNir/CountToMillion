#include "WinAPIException.h"


WinAPIException::WinAPIException(DWORD err) : std::runtime_error("WINAPI error:" + std::to_string(err)){
	// Left blank intentonaly
}