#ifndef SRC_BASE_STRING_STRING_CONVERT_H_
#define SRC_BASE_STRING_STRING_CONVERT_H_

#include <string>
#include <vector>

#include "base/base_export.h"

namespace base {

// Notice: the memory for dest must have been allocated and the size is at least
// length+1
BASE_EXPORT void AnsiToUnicode(wchar_t* dest,
                               const char* data,
                               const size_t length);

// Notice: the memory for dest must have been allocated and the size is at least
// 2*length+1
BASE_EXPORT void UnicodeToAnsi(char* dest,
                               const wchar_t* data,
                               const size_t length);

BASE_EXPORT std::wstring AnsiToUnicode(const std::string& data);

BASE_EXPORT std::string UnicodeToAnsi(const std::wstring& data);

BASE_EXPORT std::string StrToUpper(const std::string& str);

BASE_EXPORT bool IsDigitStrs(const std::string& str);

BASE_EXPORT bool StartWith(const std::string& target, const std::string& sub);

BASE_EXPORT std::vector<std::string> SplitStr(const std::string& s, char delim);

}  // namespace base

#endif  // SRC_BASE_STRING_STRING_CONVERT_H_