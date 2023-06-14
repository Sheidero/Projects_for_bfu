#include <iostream> 
#include "log.hpp"

int main(){
    perfect::Log::SetLogLevel(perfect::LogLevel::RELEASE);
    perfect::Log::SetLogPath("lab_17_custom_log/build/Log.txt");
    perfect::Log::Whrite("Perfect");
    return 0;
}