#pragma once

#pragma once
#include <string>
#include <iostream>

#ifdef MYLEAVERLIB_EXPORTS
#define MYLEAVERLIB_API __declspec(dllexport)
#else
#define MYLEAVERLIB_API __declspec(dllimport)
#endif

class MyLeaverLib
{
public:
	MYLEAVERLIB_API static void byebye(std::string& who_to_say_bye);
};