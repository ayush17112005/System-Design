// ------------------------------ Sturctual Pattern -----------------------------
#include <iostream>
#include <memory>
#include <string>
using namespace std;
class Coffee
{
public:
    virtual string GetDescription() const = 0;
    virtual double GetCost() const = 0;
    virtual ~Coffee() = default;
};

// Concrete Component
class SimpleCoffee : public Coffee
{
public:
    string GetDescription() const override { return "Simple Coffee"; }

    double GetCost() const override { return 5.0; }
};

// Decorator
class CoffeeDecorator : public Coffee
{
protected:
    Coffee *coffee_;

public:
    explicit CoffeeDecorator(Coffee *coffee)
        : coffee_(coffee) {}

    string GetDescription() const override
    {
        return coffee_->GetDescription();
    }

    double GetCost() const override { return coffee_->GetCost(); }
};

// Milk Decorator
class MilkDecorator : public CoffeeDecorator
{
public:
    explicit MilkDecorator(Coffee *coffee)
        : CoffeeDecorator(coffee) {}

    string GetDescription() const override
    {
        return coffee_->GetDescription() + ", Milk";
    }

    double GetCost() const override { return coffee_->GetCost() + 1.5; }
};

// Sugar Decorator
class SugarDecorator : public CoffeeDecorator
{
public:
    explicit SugarDecorator(Coffee *coffee)
        : CoffeeDecorator(coffee) {}

    string GetDescription() const override
    {
        return coffee_->GetDescription() + ", Sugar";
    }

    double GetCost() const override { return coffee_->GetCost() + 0.5; }
};

int main()
{
    Coffee *my_coffee = new SimpleCoffee();
    cout << "Cost: " << my_coffee->GetCost()
         << "; Description: " << my_coffee->GetDescription() << endl;

    my_coffee = new MilkDecorator(my_coffee);
    cout << "Cost: " << my_coffee->GetCost()
         << "; Description: " << my_coffee->GetDescription() << endl;

    my_coffee = new SugarDecorator(my_coffee);
    cout << "Cost: " << my_coffee->GetCost()
         << "; Description: " << my_coffee->GetDescription() << endl;

    Coffee *my_coffee1 = new SimpleCoffee();
    my_coffee1 = new SugarDecorator(my_coffee1);
    cout << "Cost: " << my_coffee1->GetCost()
         << "; Description: " << my_coffee1->GetDescription() << endl;

    return 0;
}