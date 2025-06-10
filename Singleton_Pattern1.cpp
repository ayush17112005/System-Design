#include <bits/stdc++.h>
using namespace std;
// a class must have only one object
// ensures client cannot make more than 1 object

// so we can make constructor of a class private which doesn't allow instanstation of class further
class A
{
private:
    A() = default;
    // Now if we create the obj of this class it will throw error
};

// void Print()
// {
//     static int a = 1; // this a will now act as the global var but it can't be access outside this fucnt
//     a++;
//     cout << a << endl;
// }

class B
{
public:
    // static fucn are associted with the class no the obj;
    static void Print()
    {
        cnt_++;
        // we cant use the non static variable in static functions inside a class . Eg (int cnt_ is not possible)
        // We must make the variable static in order to use within the static function . Eg (static int cnt_)
        cout << cnt_ << endl;
    }
    void hello()
    {
        cout << "hello" << endl;
    }

private:
    // We cant initialise the static varibales within the class
    // Declaration
    static int cnt_;
    //
};
// Definition
int B::cnt_ = 0;
// when we declare a method as static within a class then we dont need to create object for that class
// inorder to call that method we can directly call without creating object

int main()
{
    // B b;
    // b.Print();
    B::Print(); // only static fucn can be called this way only
}