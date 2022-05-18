#pragma once

#include <iostream>

namespace CSWrapper {
	class Wrapper
	{
	public:
		__declspec(dllimport) static void WrapperMethod1();
		__declspec(dllimport) static void WrapperMethod2();
		__declspec(dllimport) static void WrapperMethod3();
		__declspec(dllimport) static void WrapperMethod4();
		__declspec(dllimport) static void WrapperMethod5();
		__declspec(dllimport) static void WrapperMethod6();
		__declspec(dllimport) static void WrapperMethod7();
		__declspec(dllimport) static void WrapperMethod8();
		__declspec(dllimport) static void GetTime(int& year, int& month, int& day);
	};
}

