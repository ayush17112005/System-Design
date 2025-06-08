// ---------------S.O.L.I.D Principles-------------------
// L - Liskov Substitution Principle (LSP)
// Subclasses should be replaceable with their base classes without changing the behavior of the program.

#include <bits/stdc++.h>
using namespace std;

// Base class: Rectangle
class Rectangle
{
public:
    // Constructor to set length and width
    Rectangle(int length, int width) : length_(length), width_(width) {}
    virtual int GetPerimeter()
    {
        return 2 * (length_ + width_);
    }
    // Function to get perimeter of rectangle
    // virtual int GetPerimeter()
    // {
    //     return 2 * (length_ + width_);
    // }

    // Function to get area of rectangle
    int GetArea()
    {
        return length_ * width_;
    }

private:
    int length_, width_; // Dimensions of rectangle
};

// Derived class: Square
class Square : public Rectangle
{
public:
    // Constructor that passes equal sides to the Rectangle constructor
    Square(int l) : l_(l), Rectangle(l, l) {}
    // below code breaks the class Rectangle so it doesnt follow Liskov
    // int GetPerimeter()
    // {
    //     assert(2==3);
    //     return 0;
    // }

private:
    int l_; // This is not really needed, but kept here for example
};

// Function that works on a Rectangle reference and returns area and perimeter
pair<int, int> GetRectangleInfo(Rectangle &rct)
{
    // Since it uses only base class methods, it should also work with derived class
    return {rct.GetArea(), rct.GetPerimeter()};
}

int main()
{
    // Creating a Rectangle object
    Rectangle rct(2, 4);

    // Creating a Square object
    Square square(5);

    // Getting info for Rectangle
    auto it = GetRectangleInfo(rct);
    cout << it.first << " " << it.second << endl;

    // Getting info for Square using same function — LSP in action
    auto it2 = GetRectangleInfo(square);
    cout << it2.first << " " << it2.second << endl;

    // Output should be correct for both objects if LSP is followed
}
