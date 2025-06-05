// ------------- Composition-----------------------
#include <bits/stdc++.h>
using namespace std;

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
    Person(string PersonName) : heart(PersonName), person_(PersonName)
    {
        cout << "Person created: " << person_ << endl;
    };

    ~Person()
    {
        cout << "Person destroyed" << person_ << endl;
    }

private:
    Heart heart; // existence of heart object depend upon person object if person is destroyed, heart is also destroyed
    string person_;
};

int main()
{
    Person person("John Doe");
    Person person2("Ronaldo");

    // When person is destroyed the heart object will also be destroyed
    // Heart heart; // Heart object is created
    // Heart object will be destroyed automatically when person object goes out of scope
    return 0;
}