// ---------------------------- S.O.L.I.D Principles ----------------------------
// Factory Pattern Example
#include <bits/stdc++.h>
using namespace std;

// Interface class
class ShapeInterface
{
public:
    virtual void Draw() = 0; // Pure virtual function for drawing the shape
};

class Circle : public ShapeInterface
{
public:
    void Draw() override
    {
        cout << "Drawing Circle" << endl;
    }
};

class Square : public ShapeInterface
{
public:
    void Draw() override
    {
        cout << "Drawing Square" << endl;
    }
};
class ShapeFactory
{
public:
    // Factory method to create shapes based on string input
    ShapeInterface *GetShape(const string &str)
    {
        if (str == "Circle")
            return new Circle();
        if (str == "Square")
            return new Square();
    }
};

int main()
{
    ShapeFactory factory;
    string shape_;
    cin >> shape_;
    ShapeInterface *shape1 = factory.GetShape(shape_);
    shape1->Draw();
    // here user is prompted to enter the shape type (Circle or Square)
    // we dont know at compile time which shape will be created
    // so we use a factory method to create the shape dynamically based on user input.

    // Clean up
    delete shape1;

    return 0;
}
