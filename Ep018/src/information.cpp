#include "information.h"

namespace Logging{
    std::string getOsName()
    {
        #ifdef _WIN32
        return "Windows 32-bit";
        #elif _WIN64
        return "Windows 64-bit";
        #elif __APPLE__ || __MACH__
        return "Mac OSX";
        #elif __linux__
        return "Linux";
        #elif __FreeBSD__
        return "FreeBSD";
        #elif __unix || __unix__
        return "Unix";
        #else
        return "Other";
        #endif
    }
};