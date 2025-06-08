// -------------------S.O.L.I.D Principles-------------------
// O - Open/Closed Principle (OCP)
// classes should be open for extension but closed for modification.
#include <bits/stdc++.h>
using namespace std;
class StringFunction
{
public:
    virtual string Edit(const string &str1, const string &str2) = 0; // Pure virtual function
};

class Append : public StringFunction
{
public:
    string Edit(const string &str1, const string &str2) override
    {
        return str1 + str2; // Appends str2 to str1
    }
};

class ReverseAppend : public StringFunction
{
public:
    string Edit(string const &s1, string const &s2) override
    {
        return s2 + s1;
    }
};

class CustomAppend : public StringFunction
{
    string Edit(const string &s1, const string &s2) override
    {
        return s1 + s1 + s2; // Custom append logic
    }
};

class TextEditor
{
public:
    string Format(const string &str1, const string &str2, StringFunction &func)
    {
        return func.Edit(str1, str2);
    }
};

int main()
{
    TextEditor editor;
    Append append;
    ReverseAppend reverseAppend;
    CustomAppend customAppend;

    string str1 = "Hello";
    string str2 = "World";

    cout << "Append: " << editor.Format(str1, str2, append) << endl;
    cout << "Reverse Append: " << editor.Format(str1, str2, reverseAppend) << endl;
    cout << "Custom Append: " << editor.Format(str1, str2, customAppend) << endl;

    return 0;
}