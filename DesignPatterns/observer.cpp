/*
    Observer Pattern -
        A one-to-many dependency between objects so that when one object (Subject)
        changes its state, all its dependent objects (Observers) are automatically
        notified and updated.

    => Use Observer Pattern when one object changes and many other objects must update automatically, without tight coupling.

    Eg: Weather Station
        - Many displays, phone, tv, car, watch
        - When temp changes, all displays must update automatically
        - without observer, subject must manually call functions of observers -> tv.update, phone.update etc
        - there will be tight coupling, diff to add/remove observer

    Other eg: GUI event listeners, messaging system, event driven systems, stock updates
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Observer
{
public:
    virtual void update(int temperature) = 0;
    virtual ~Observer() = default;
};

class PhoneDisplay : public Observer
{
public:
    void update(int temperature) override
    {
        std::cout << "Phone Display: Temperature is " << temperature << "°C\n";
    }
};

class TVDisplay : public Observer
{
public:
    void update(int temperature) override
    {
        std::cout << "TV Display: Temperature is " << temperature << "°C\n";
    }
};

class Subject
{
public:
    virtual void addObserver(Observer *obs) = 0;
    virtual void removeObserver(Observer *obs) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default;
};

class WeatherStation : public Subject
{
    int temperature;
    std::vector<Observer *> observers;

public:
    void setTemperature(int temp)
    {
        temperature = temp;
        notifyObservers();
    }

    int getTemperature() const { return temperature; }

    void addObserver(Observer *obs) override
    {
        observers.push_back(obs);
    }

    void removeObserver(Observer *obs) override
    {
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void notifyObservers() override
    {
        for (auto *obs : observers)
            obs->update(temperature);
    }
};

// CLient code:
int main()
{
    WeatherStation station;

    PhoneDisplay phone;
    TVDisplay tv;

    station.addObserver(&phone);
    station.addObserver(&tv);

    station.setTemperature(30);
    station.setTemperature(35);
}
