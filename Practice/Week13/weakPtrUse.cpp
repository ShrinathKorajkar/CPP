#include <iostream>
#include <memory>

// Cause leak
class Parent;
class Child;

class Parent
{
public:
    std::shared_ptr<Child> child;

    Parent() { std::cout << "Parent created\n"; }
    ~Parent() { std::cout << "Parent destroyed\n"; }
};

class Child
{
public:
    std::shared_ptr<Parent> parent;

    Child() { std::cout << "Child created\n"; }
    ~Child() { std::cout << "Child destroyed\n"; }
};

//
//* Solution using weak pointer

class Parent2;
class Child2;

class Parent2
{
public:
    std::shared_ptr<Child2> child2;

    Parent2() { std::cout << "Parent2 created\n"; }
    ~Parent2() { std::cout << "Parent2 destroyed\n"; }
};

class Child2
{
public:
    std::weak_ptr<Parent2> parent2; // <-- FIX

    Child2() { std::cout << "Child2 created\n"; }
    ~Child2() { std::cout << "Child2 destroyed\n"; }
};

int main()
{
    {
        auto p = std::make_shared<Parent>();
        auto c = std::make_shared<Child>();

        p->child = c;
        c->parent = p; // <--- PROBLEM
    }
    // Program exits scope, but destructors DO NOT RUN

    {
        auto p = std::make_shared<Parent2>();
        auto c = std::make_shared<Child2>();

        p->child2 = c;
        c->parent2 = p; // weak assignment
    }
    // When main exits, destructors WILL run
}
