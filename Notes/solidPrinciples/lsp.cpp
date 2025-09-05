#include <stdexcept>

// bad - Code expects Sensor::read() to always return a valid reading, but derived class changes behavior drastically.
class Sensor
{
public:
    virtual int read() { return 42; }
};

class FaultySensor : public Sensor
{
public:
    int read() override
    {
        throw std::runtime_error("Sensor disconnected");
    }
};

void processSensor(Sensor *s)
{
    int value = s->read(); // Assumes valid integer
    // If FaultySensor is passed, it breaks the assumption
}

// Good
class Sensor2
{
public:
    virtual bool read(int &value)
    {
        value = 42;
        return true; // success
    }
};

class FaultySensor2 : public Sensor2
{
public:
    bool read(int &value) override
    {
        return false; // consistent way to signal error
    }
};
