#include <vector>
#include <iostream>

class Shape
{
public:
    virtual void Draw() const = 0;
};

class Square : public Shape
{
public:
    virtual void Draw() const;
};

class Circle : public Shape
{
public:
    virtual void Draw() const;
};

void DrawAllShapes(std::vector<Shape *> &list)
{
    std::vector<Shape *>::iterator i;
    for (i = list.begin(); i != list.end(); i++)
        (*i)->Draw();
}

// bad
class SensorManager
{
public:
    void readSensor(const std::string &type)
    {
        if (type == "Temperature")
        {
            // Read from temperature sensor
        }
        else if (type == "Pressure")
        {
            // Read from pressure sensor
        }
        // Adding a new sensor means modifying this class
    }
};

// Good
class ISensor
{
public:
    virtual int read() = 0;
    virtual ~ISensor() = default;
};

class TemperatureSensor : public ISensor
{
public:
    int read() override { return 25; } // Simulated reading
};

class PressureSensor : public ISensor
{
public:
    int read() override { return 1013; }
};

class SensorManager
{
public:
    void addSensor(ISensor *sensor)
    {
        sensors.push_back(sensor);
    }
    void readAll()
    {
        for (auto sensor : sensors)
        {
            int value = sensor->read();
            // Process value
        }
    }

private:
    std::vector<ISensor *> sensors;
};
