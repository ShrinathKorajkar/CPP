
// bad - If a class only supports printing, it still need to implement scan and fix
class IPrinter
{
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};

// Good
class IPrintable
{
public:
    virtual void print() = 0;
};
class IScannable
{
public:
    virtual void scan() = 0;
};
class IFaxable
{
public:
    virtual void fax() = 0;
};
