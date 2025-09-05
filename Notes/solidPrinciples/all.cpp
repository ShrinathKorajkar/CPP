#include <string>

// ISP: Small, focused interfaces
class ISensor
{
public:
    virtual float readTemperature() = 0;
    virtual ~ISensor() = default; // LSP-safe
};

class IComm
{
public:
    virtual void send(const std::string &data) = 0;
    virtual ~IComm() = default;
};

class ILogger
{
public:
    virtual void log(const std::string &message) = 0;
    virtual ~ILogger() = default;
};

// SRP: Each class has ONE responsibility
class TempSensorI2C : public ISensor
{
public:
    float readTemperature() override
    {
        // Read temperature via I2C
        return 25.0;
    }
};

class TempSensorSPI : public ISensor
{
public:
    float readTemperature() override
    {
        // Read temperature via SPI
        return 26.0;
    }
};

class UARTComm : public IComm
{
public:
    void send(const std::string &data) override
    {
        // Send data via UART
    }
};

class FlashLogger : public ILogger
{
public:
    void log(const std::string &message) override
    {
        // Write log to flash
    }
};

// OCP & DIP: High-level module depends on abstractions
class DataMonitor
{
    ISensor *sensor; // Abstraction
    IComm *comm;     // Abstraction
    ILogger *logger; // Abstraction
public:
    DataMonitor(ISensor *s, IComm *c, ILogger *l)
        : sensor(s), comm(c), logger(l) {}

    void process()
    {
        float temp = sensor->readTemperature();
        logger->log("Temperature: " + std::to_string(temp));
        comm->send("Temp:" + std::to_string(temp));
    }
};

int main()
{
    TempSensorI2C sensor;
    UARTComm uart;
    FlashLogger logger;

    DataMonitor monitor(&sensor, &uart, &logger);
    monitor.process(); // Works with any ISensor, IComm, ILogger implementation
}
