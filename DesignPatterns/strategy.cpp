/*
    Strategy Pattern -
        Define a family of algorithms - itFlys, CantFly
        Make them interchangeble at runtime - Creating interface
        And keep the algorithm seprate from the object that uses it -> has a relationship between user and interface

    => Behaviour can change without modifying the class using it, dynamic behaviour change

    Eg: Payment Strategy
        - User can pay via, Credit card, UPI, PayPal
        - without strategy -> if(paymentType == CREDIT_CARD) elseif ladder
        - voilates Open Closed principle

    Other eg - file saving, compression strategies
*/
#include <iostream>

class PaymentStrategy
{
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() = default;
};

class CreditCardPayment : public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        std::cout << "Paid " << amount << " using Credit Card\n";
    }
};

class PayPalPayment : public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        std::cout << "Paid " << amount << " using PayPal\n";
    }
};

class UpiPayment : public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        std::cout << "Paid " << amount << " using UPI\n";
    }
};

// Context class - uses strategy but doesn't know which one
class ShoppingCart
{
    PaymentStrategy *paymentStrategy;

public:
    void setPaymentStrategy(PaymentStrategy *strategy)
    {
        paymentStrategy = strategy;
    }

    void checkout(int amount)
    {
        paymentStrategy->pay(amount);
    }
};

// User - client
int main()
{
    ShoppingCart cart;

    CreditCardPayment c;
    UpiPayment u;
    PayPalPayment p;

    cart.setPaymentStrategy(&u);
    cart.checkout(100); // UPI payment

    cart.setPaymentStrategy(&p);
    cart.checkout(250); // PayPal payment
}
