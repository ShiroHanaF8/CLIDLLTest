#include "Wrapper.h"

#include <msclr/marshal_cppstd.h>

#include <ctime>

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

	void Wrapper::GetTime(int& year, int& month, int& day)
	{
		try {
			auto ipAny = gcnew System::Net::IPEndPoint(System::Net::IPAddress::Any, 0);
			auto objSck = gcnew System::Net::Sockets::UdpClient(ipAny);
			auto sdat = gcnew array<System::Byte>(48);
			sdat[0] = 0xB;
			objSck->Send(sdat, sdat->GetLength(0), "time.windows.com", 123);

			auto rdat = objSck->Receive(ipAny);

			pin_ptr<byte> rcvPtr = &rdat[40];
			tm time = {};
			time_t tmsecond = 
				(time_t)rdat[40] * 16777216 +
				(time_t)rdat[41] * 65536 +
				(time_t)rdat[42] * 256 +
				(time_t)rdat[43];
			localtime_s(&time, &tmsecond);

			year = 1900 + time.tm_year - 70; // 1970/1/1 and 1900/1/1
			month = time.tm_mon + 1;
			day = time.tm_mday;
		}
		catch (...)
		{
			auto now = System::DateTime::Now;
			year = now.Year;
			month = now.Month;
			day = now.Day;
		}
	}
}