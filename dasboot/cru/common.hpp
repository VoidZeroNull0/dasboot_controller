#pragma once

#include <sstream>

#define DASBOOTD_SOCK "/var/run/dasboot.sock"

class MakeString {
public:
    template<class T>
    MakeString& operator<< (const T& arg) {
        Stream << arg;
        return *this;
    }

    operator std::string() const { // NOLINT(google-explicit-constructor,hicpp-explicit-conversions)
        return Stream.str();
    }
protected:
    std::stringstream Stream;
};

namespace NCommon {
class TStatus {
public:
    enum ECode {
        Success = 0,
        Failed = 1,
        Ignored = 2
    };

    ECode Code = ECode::Success;
    std::string Error = "";
};

} // namespace NCommon
