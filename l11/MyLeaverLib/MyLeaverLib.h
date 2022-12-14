#pragma once

#pragma once
#include <string>
#include <iostream>

#ifdef _WIN32
#ifdef MYLEAVERLIB_EXPORTS
#define MYLEAVERLIB_API __declspec(dllexport)
#else
#define MYLEAVERLIB_API __declspec(dllimport)
#endif
#endif


class MyLeaverLib
{
public:
#ifdef _WIN32
	MYLEAVERLIB_API	
#endif
	static void byebye(std::string& who_to_say_bye);
};