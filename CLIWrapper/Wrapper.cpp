#include "Wrapper.h"

#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;

using namespace CSharpLibraly;

namespace CSWrapper {

	void Wrapper::WrapperMethod1()
	{
		WPFClass::CSMethod1();
	}

	void Wrapper::WrapperMethod2()
	{
		WPFClass::CSMethod2();
	}

	void Wrapper::WrapperMethod3()
	{
		WPFClass::CSMethod3();
	}

	void Wrapper::WrapperMethod4()
	{
		WPFClass::CSMethod4();
	}

	void Wrapper::WrapperMethod5()
	{
		WPFClass::CSMethod5();
	}

	void Wrapper::WrapperMethod6()
	{
		WPFClass::CSMethod6();
	}

	void Wrapper::WrapperMethod7()
	{
		WPFClass::CSMethod7();
	}


	void Wrapper::WrapperMethod8()
	{
		WPFClass::CSMethod8();
		//return marshal_as<std::wstring>(asmsM);
	}
}