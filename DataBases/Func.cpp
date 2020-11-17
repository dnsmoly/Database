#include "Func.h"


std::string& ConvertTostring(String^ s, std::string& os)
{
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
	// TODO: вставьте здесь оператор return
}

String^ ConvertToString(std::string& os, String^ s)
{
	s = gcnew System::String(os.c_str());
	return s;
	
	// TODO: вставьте здесь оператор return
}

std::string& ConvertTostring(String^ s)
{
	std::string os;
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return std::string(os);
	// TODO: вставьте здесь оператор return
}

String^ ConvertToString(std::string& os)
{
	System::String^ s = gcnew System::String(os.c_str());
	return s;
	// TODO: вставьте здесь оператор return
}
