#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
namespace perfect{
enum class LogLevel{
    ALL,
    INFO,
    DEBUG,
    ERROR,
    RELEASE
};

class Log{
private:
    static std::ofstream m_out;
    static LogLevel m_logLevel;
    std::stringstream m_ss;
public:
    Log(LogLevel logLevel){
        m_logLevel = logLevel;
    }
    static void SetLogLevel(LogLevel logLevel){
        m_logLevel = logLevel; 
    }
    static void SetLogPath(const std::string& path){
        m_out.open(path);
    }
    static void Whrite(const std::string& msg){
        char time[80];
        std::time_t timestamp = std::time(0);
        std::strftime(time, 80, "%x %X - ", std::localtime(&timestamp));
        if (m_logLevel == LogLevel::RELEASE){
           m_out << "RELEASE: " << time << msg << std::endl; 
        }
        else {
            std::cerr << time << msg << std::endl;
            m_out << "Other: " << time << msg << std::endl; 
        }
        m_out.flush(); // Сбросить в файл всё, что есть в буфере
    }
    ~Log(){
        switch (m_logLevel)
        {
        case LogLevel::ALL:
            std::cerr << "ALL" << m_ss.str() <<  std::endl;
            break;
        case LogLevel::INFO:
            std::cerr << "[INFO]" << m_ss.str() << std::endl;
            break;
        case LogLevel::DEBUG:
            std::cerr << "DEBUG" << m_ss.str() << std::endl;
            break;
        case LogLevel::ERROR:
            std::cerr << "ERROR" << m_ss.str() << std::endl;
            break;
        case LogLevel::RELEASE:
            std::cerr << "RELEASE" << m_ss.str() << std::endl;
            break;
        default:
            break;
        }
    }
    template<typename T>
    Log& operator << (const T& t){
        m_ss << t;
        return *this;
    }
};
}
