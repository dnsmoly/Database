#pragma once

#include <string>

using namespace System;

std::string& ConvertTostring(String^ s, std::string& os);
String^ ConvertToString(std::string& os, String^ s);
std::string& ConvertTostring(String^ s);
String^ ConvertToString(std::string& os);


