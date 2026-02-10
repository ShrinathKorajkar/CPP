/*
    Factory Pattern -
        creational design pattern that provides an interface for creating objects,
        but lets subclasses or a factory class decide which class to instantiate.
        - Decouples object creation from usage
        - Polymorphism without if-else/switch
        - Exact type of obj is decided at runtime (plugin modual design)

    => provides a centralized method to create objects, while hiding the object creation logic from the caller.

    Eg: Animal
        - Instead of Dog* d = new Dog(), Animal* a = AnimalFactory::create("Dog");

    Applications - Games -> creating enemies, weapons, GUI, device creation, serialization/deserialization
*/
#include <iostream>
#include <memory>
#include <functional>
#include <unordered_map>

class IAuthProvider
{
public:
    virtual bool authenticate(const std::string &user) = 0;
    virtual ~IAuthProvider() = default;
};

class PasswordAuth : public IAuthProvider
{
public:
    bool authenticate(const std::string &user) override
    {
        std::cout << "Authenticating " << user << " using PasswordAuth\n";
        return true;
    }
};

class OAuth2Auth : public IAuthProvider
{
public:
    bool authenticate(const std::string &user) override
    {
        std::cout << "Authenticating " << user << " using OAuth2Auth\n";
        return true;
    }
};

class SmartCardAuth : public IAuthProvider
{
public:
    bool authenticate(const std::string &user) override
    {
        std::cout << "Authenticating " << user << " using SmartCardAuth\n";
        return true;
    }
};

class AuthFactory
{
public:
    using Creator = std::function<std::unique_ptr<IAuthProvider>()>;

    static AuthFactory &instance()
    {
        static AuthFactory f;
        return f;
    }

    void registerType(const std::string &name, Creator c)
    {
        registry[name] = std::move(c);
    }

    std::unique_ptr<IAuthProvider> create(const std::string &name)
    {
        if (!registry.count(name))
            throw std::runtime_error("Unknown auth type: " + name);
        return registry[name]();
    }

private:
    std::unordered_map<std::string, Creator> registry;
};

void registerAuthProviders()
{
    AuthFactory::instance().registerType("password", []()
                                         { return std::make_unique<PasswordAuth>(); });
    AuthFactory::instance().registerType("oauth", []()
                                         { return std::make_unique<OAuth2Auth>(); });
    AuthFactory::instance().registerType("smartcard", []()
                                         { return std::make_unique<SmartCardAuth>(); });
}

int main()
{
    registerAuthProviders();

    std::string configuredMethod = "smartcard"; // Loaded from config.json or /etc/daemon.conf

    auto auth = AuthFactory::instance().create(configuredMethod);

    auth->authenticate("shrinath");
}
