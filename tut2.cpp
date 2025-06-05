// -------------------------- Aggregation --------------------------
#include <bits/stdc++.h>
using namespace std;
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
    string address_;
};

class Heart
{
public:
    Heart(string PersonName) : PersonName_(PersonName)
    {
        cout << "Heart created for " << PersonName_ << endl;
    }
    ~Heart()
    {
        cout << "Heart destroyed" << PersonName_ << endl;
    }

private:
    string PersonName_;
};

class Person
{
public:
    Person(string PersonName, Home *home) : heart(PersonName), person_(PersonName), home_(home)
    {
        cout << "Person created: " << person_ << endl;
    };

    ~Person()
    {
        cout << "Person destroyed" << person_ << endl;
    }

    void GetAddress()
    {
        cout << "Home address: " << home_->address_ << endl;
    }

private:
    Heart heart; // Composition: Heart object is part of Person object, if Person is destroyed, Heart is also destroyed
    string person_;
    Home *home_; // Aggregation: Home object can exist independently of Person object
};

int main()
{
    Home home("123 Main St");
    Person *person1 = new Person("John Doe", &home);
    Person *person2 = new Person("Ronaldo", &home);
    person1->GetAddress();
    delete person1; // When person1 is destroyed, the heart object will also be destroyed
    person2->GetAddress();
    delete person2; // When person2 is destroyed, the heart object will also be destroyed
    // When person is destroyed, the heart object will also be destroyed
    // Home object will not be destroyed automatically when person object goes out of scope
    return 0;
}