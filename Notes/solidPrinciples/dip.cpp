#include <string>

class Logger
{
public:
    void logToFlash(const std::string &msg) { /* Write to flash */ }
};
class SystemMonitor
{
    Logger logger; // Tight coupling
};

// good
class ILogger
{
public:
    virtual void log(const std::string &msg) = 0;
};
class FlashLogger : public ILogger
{
    void log(const std::string &msg) override { /* flash write */ }
};
class ConsoleLogger : public ILogger
{
    void log(const std::string &msg) override { /* serial print */ }
};

class SystemMonitor2
{
    ILogger *logger;

public:
    SystemMonitor2(ILogger *l) : logger(l) {}
    void monitor() { logger->log("System OK"); }
};
