#include <stdexcept>
#include <iostream>

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

class Bird
{
public:
    virtual void fly()
    {
        std::cout << "Bird is flying" << std::endl;
    }
};

class Ostrich : public Bird
{
public:
    void fly() override
    {
        // Ostriches can't fly, but we are forced to implement this!
        throw std::runtime_error("Ostrich can't fly!");
    }
};

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

// Base class has no assumption of flying
class Bird2
{
public:
    virtual void sound()
    {
        // cout << "Bird sound" << endl;
    }
};

class FlyingBird : public Bird2
{
public:
    virtual void fly() = 0;
};

class Sparrow2 : public FlyingBird
{
public:
    void sound() override
    {
        // cout << "Chirp chirp" << endl;
    }
    void fly() override
    {
        // cout << "Sparrow is flying" << endl;
    }
};

class Ostrich2 : public Bird2
{
public:
    void sound() override
    {
        // cout << "Boom boom" << endl;
    }
};
