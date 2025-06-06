#include <bits/stdc++.h>
using namespace std;

class Person; // Forward declaration
class Home
{
public:
    Home(string address) : address_(address)
    {
        cout << "Home address created: " << address_ << endl;
    }
    ~Home()
    {
        cout << "Home address destroyed: " << address_ << endl;
    }
    void personInfo();
    string address_;
    vector<Person *> residents_; // Aggregation: Home can have multiple Person objects as residents
};

class Person
{
public:
    Person(string PersonName) : personName_(PersonName)
    {
        cout << "Person created: " << personName_ << endl;
    }

    ~Person()
    {
        cout << "Person destroyed" << personName_ << endl;
    }

    void AddHome(Home *home)
    {
        homes_.push_back(home);
        home->residents_.push_back(this); // Add this person to the home's residents
        cout << personName_ << " added to home at " << home->address_ << endl;
    }

    void GetHomes()
    {
        cout << personName_ << " lives in the following homes: ";
        for (auto home : homes_)
        {
            cout << home->address_ << " ";
        }
        cout << endl;
    }
    string personName_;
    vector<Home *> homes_; // Association : Person can have multiple Home objects
};
void Home ::personInfo()
{
    cout << "Home at " << address_ << " has the following residents: ";
    for (auto resident : residents_)
    {
        cout << resident->personName_ << " ";
    }
    cout << endl;
}
int main()
{
    Home *home1 = new Home("123 Main St");
    Home *home2 = new Home("456 Elm St");
    Home *home3 = new Home("Etah, UP, India");
    Person *person1 = new Person("Alice");
    Person *person2 = new Person("Bob");
    Person *person3 = new Person("Ayushman");
    person1->AddHome(home1);
    person1->AddHome(home2);
    person3->AddHome(home3);
    person2->AddHome(home1);
    person3->GetHomes();
    home3->personInfo();
    return 0;
}
