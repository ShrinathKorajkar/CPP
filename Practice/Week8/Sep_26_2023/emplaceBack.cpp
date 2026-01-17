#include <iostream>
#include <vector>
#include <string>

class Person
{
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a)
    {
        std::cout << "Constructor called for " << name << "\n";
    }

    Person(const Person &other)
    {
        std::cout << "Copy constructor called for " << other.name << "\n";
        name = other.name;
        age = other.age;
    }

    Person(Person &&other) noexcept
    {
        std::cout << "Move constructor called for " << other.name << "\n";
        name = other.name;
        age = other.age;
    }

    ~Person()
    {
        std::cout << "Destructor called for " << name << "\n";
    }
};

int main()
{
    std::vector<Person> people;
    people.reserve(3); // prevent reallocation for clarity

    Person p("Alice", 25);

    // people.push_back(p);                 // Copy
    // people.push_back(Person("Bob", 30)); // Move

    people.emplace_back(p);         // Copy
    people.emplace_back("Bob", 30); // directly constructs
}
