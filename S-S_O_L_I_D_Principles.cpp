// ----------------------- SOLID Principles -----------------------

// S - Single Responsibility Principle (SRP)

#include <bits/stdc++.h>
using namespace std;
/*
class IndianIncome {
public:
    IndianIncome(double income) : income_(income) {}

    double GetAverageIncomeTax()
    {
        return income_ * 15; // Example tax calculation
    }

    void PrintIncomeTax()
    {
        cout << "Average Income Tax: " << GetAverageIncomeTax() << endl;
    }

private:
    double income_;
};
*/

// Above class has 3 responsibilities:
// 1. Calculate average income tax
// 2. Print average income tax
// 3. Store income data
// To follow SRP, we can separate these responsibilities into different classes.

// Below is the refactored code that adheres to the Single Responsibility Principle (SRP):
// The IndianIncome class now only has the responsibility of storing income data.
class IndianIncome
{
public:
    IndianIncome(double income) : income_(income) {}

    double GetIncome()
    {
        return income_;
    }

private:
    double income_;
};

// So this class now only has the responsibility of calculating average income tax.
class IncomeTaxCalculator
{
public:
    double CalculateAverageIncomeTax(IndianIncome &income)
    {
        return income.GetIncome() / 15; // Example tax calculation
    }
};
// Now this class has the responsibility of printing the average income tax.
class Printer
{
    void PrintIncomeTax(IndianIncome &income)
    {
        cout << "Average Income Tax: " << income.GetIncome() << endl; // Example tax calculation
    }
};

// So all the three classes now have a single responsibility each.
int main()
{
    IndianIncome income(150000); // Example income
    IncomeTaxCalculator taxCalculator;
    Printer printer;

    double averageTax = taxCalculator.CalculateAverageIncomeTax(income);
    cout << "Average Income Tax: " << averageTax << endl;

    return 0;
}