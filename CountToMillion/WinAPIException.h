#pragma once
#include <stdexcept>
#include <string>
#include <Windows.h>


class WinAPIException : public std::runtime_error
{
public:
	WinAPIException(DWORD err);
};

