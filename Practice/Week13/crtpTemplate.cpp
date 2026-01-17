// Withour CRTP - CRTP (Curiously Recurring Template Pattern)
class Shape
{
public:
    virtual double area() const = 0;
};

class Rectangle : public Shape
{
public:
    double area() const override
    {
        return 10.0;
    }
};

// With CRTP
/*
    CRTP enables:
        Static polymorphism (compile-time polymorphism)
        Zero runtime cost abstraction
        Code reuse without virtual functions
        Behavior customization by derived class known at compile time
*/
template <typename Derived>
class Shape2
{
public:
    double area() const
    {
        // Need to use different name, same name will cause infinite recursion
        // Even though object is Rectange, CTRP is static -> function lookup is compile-time -> calls Shape::area()
        return static_cast<const Derived *>(this)->areaImpl();
    }
};

class Rectangle2 : public Shape2<Rectangle2>
{
public:
    double areaImpl() const
    {
        return 10.0;
    }
};

// Some good example for code reusability
template <typename Derived>
class Comparable
{
public:
    bool operator>(const Derived &other) const
    {
        return static_cast<const Derived *>(this)->value() >
               other.value();
    }
};

class Number : public Comparable<Number>
{
public:
    int value() const { return x; }

private:
    int x;
};
